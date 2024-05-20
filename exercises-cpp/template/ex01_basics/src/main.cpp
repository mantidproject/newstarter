/**
 * Skeleton main routine
 */

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::string inputFilePath = argv[1];
    std::map<std::string, int> wordCount = countWordOccurrences(inputFilePath);

    if (wordCount.empty()) {
        std::cerr << "Error: No valid words found in the file" << std::endl;
        return 1;
    }
}