#ifndef EX1_FILE_HELPERS
#define EX1_FILE_HELPERS
#include <fstream>
#include <string>

/** Opens the file with the specified path on the InputFileStream object.
 *  @param Filename The name or path of the input file.
 *  @param InputFile The target ifstream.
 *  @throws std::runtime_eror When the file cannot be opened.
 */
void openInputFile(std::string const &Filename, std::ifstream& InputFileStream) {

/** Opens the results.txt output file on the target ofstream 
 *  overriting it if one exists already,
 *  @param OutputFileStream The target ofstream.
 *  @throws std::runtime_error When the file cannot be created.
 */
std::ofstream openOutputFile(std::ofstream& OutputFileStream);

/** Converts the content of the stream to a string.
 *  @pre The stream is open and in an error free state.
 */
std::string fileToString(std::ifstream const &File);
#endif // EX1_FILE_HELPERS
