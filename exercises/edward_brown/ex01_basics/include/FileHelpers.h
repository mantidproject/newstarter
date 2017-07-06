#include <fstream>
#include <string>

/** Opens the file with the specified path and returns the created stream.
 *  @throws std::runtime_eror When the file cannot be opened.
 */
std::ifstream openInputFile(std::string const &Filepath);

/** Opens the results.txt output file overriting it if one exists already,
 *  returns the created stream.
 *  @throws std::runtime_error When the file cannot be created.
 */
std::ofstream openOutputFile();

/** Converts the content of the stream to a string.
 *  @pre The stream is open and in an error free state.
 */
std::string fileToString(std::ifstream const &File);
