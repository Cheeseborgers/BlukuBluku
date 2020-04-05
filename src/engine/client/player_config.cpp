
#include "player_config.h"

engine::client::player_config::Player_config::Player_config() {

    libconfig::Config cfg;

    // Read the file. If there is an error, report it and exit.
    try {
        cfg.readFile("example.cfg");
    }
    catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file.\n";
        exit(0);
    }
    catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << "\n";
        exit(0);
    }

    // Get the store name.
    try {
        std::string name = cfg.lookup("name");
        std::cout << "Store name: " << name << "\n" << "\n";
    }
    catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'name' setting in configuration file.\n";
    }

    const libconfig::Setting &root = cfg.getRoot();

    // Output a list of all books in the inventory.
    try {
        const libconfig::Setting &books = root["inventory"]["books"];
        int count = books.getLength();

        std::cout << std::setw(30) << std::left << "TITLE" << "  "
                  << std::setw(30) << std::left << "AUTHOR" << "   "
                  << std::setw(6) << std::left << "PRICE" << "  "
                  << "QTY"
                  << "\n";

        for (int i = 0; i < count; ++i) {
            const libconfig::Setting &book = books[i];

            // Only output the record if all of the expected fields are present.
            std::string title;
            std::string author;
            double price;
            int qty;

            if (!(book.lookupValue("title", title)
                  && book.lookupValue("price", price)
                  && book.lookupValue("qty", qty))) {
                continue;
            }

            std::cout << std::setw(30) << std::left << title << "  "
                      << std::setw(30) << std::left << author << "  "
                      << '$' << std::setw(6) << std::right << price << "  "
                      << qty
                      << "\n";
        }
        std::cout << "\n";
    }
    catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }

    // Output a list of all books in the inventory.
    try {
        const libconfig::Setting &movies = root["inventory"]["movies"];
        int count = movies.getLength();

        std::cout << std::setw(30) << std::left << "TITLE" << "  "
                  << std::setw(10) << std::left << "MEDIA" << "   "
                  << std::setw(6) << std::left << "PRICE" << "  "
                  << "QTY"
                  << "\n";

        for (int i = 0; i < count; ++i) {
            const libconfig::Setting &movie = movies[i];

            // Only output the record if all of the expected fields are present.
            std::string title;
            std::string media;
            double price;
            int qty;

            if (!(movie.lookupValue("title", title)
                  && movie.lookupValue("media", media)
                  && movie.lookupValue("price", price)
                  && movie.lookupValue("qty", qty))) {
                continue;
            }

            std::cout << std::setw(30) << std::left << title << "  "
                      << std::setw(10) << std::left << media << "  "
                      << '$' << std::setw(6) << std::right << price << "  "
                      << qty
                      << "\n";
        }
        std::cout << "\n";
    }
    catch (const libconfig::SettingNotFoundException &nfex) {
        // Ignore.
    }
}

//-------------------------------------------------------------------------------------------------------------------//
void engine::client::player_config::Player_config::find_all_player_configs() {
    for (const auto &entry : std::filesystem::directory_iterator(this->path)) {
        std::cout << entry.path() << "\n";
    }
}

//--------------------------------------------------------------------------------------------------------------------//
bool engine::client::player_config::Player_config::check_player_config_dir_exists(const std::string &player_dir) {
    /* profiles is the directory (within the game executable) that holds all
     * the players data
     * here we check if the directory exists or not
     */

    std::filesystem::path p(player_dir);

    try {
        auto r = std::filesystem::exists(p);
        return r;
    }
    catch (const std::filesystem::filesystem_error &err) {
        engine::logger::Logger::record(
                "engine::client::player_config::Player_config: Error reading "
                "directory " + std::string(err.what())
        );

        return false;
    }
}

//--------------------------------------------------------------------------------------------------------------------//
bool engine::client::player_config::Player_config::create_player_config_dir(const std::string &player_dir) {
    std::error_code ec;

    if (!std::filesystem::create_directories(player_dir, ec)) {
        engine::logger::Logger::record(
                "engine::client::player_config::Player_config::create_player_config_dir"
                ": Error reading directory " + std::string(ec.message())
        );
        return false;
    }

    std::cout << ec.message() << "\n"; // Fun fact: In case of success ec.message() returns "Success." using gcc++.
    return true;
}

//--------------------------------------------------------------------------------------------------------------------//
unsigned char engine::client::player_config::Player_config::generate_uid_random_char() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    return static_cast<unsigned char>(dis(gen));
}

//--------------------------------------------------------------------------------------------------------------------//
std::string engine::client::player_config::Player_config::generate_hex_uid(const unsigned int len) {
    std::stringstream ss;
    for (auto i = 0; i < len; i++) {
        const auto rc = generate_uid_random_char();
        std::stringstream hexstream;
        hexstream << std::hex << int(rc);
        auto hex = hexstream.str();
        ss << (hex.length() < 2 ? '0' + hex : hex);
    }
    return ss.str();
}
//--------------------------------------------------------------------------------------------------------------------//

