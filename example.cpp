/*
This is a very simple example which parses a file path.
*/

#include <iostream>
#include "scanner.h"

int main()
{
    // example one
    // path -> [ a, b, c... ]

    std::string s = "/a/path/which/leads/to/a/file";
    Scanner scan(s);

    std::cout << s << " ->\n";

    while(scan)
    {
        auto component = scan.take_while(!match_chars("/"));

        if(!component.empty())
        {
            std::cout << component << "\n";
        }

        scan++;
    }

    // example two
    // filename -> filename + extension

    // reload the source string
    s = "file.tar.gz";
    scan.set_source(s);

    std::string filename { scan.take_while(!match_chars(".")) };
    std::string extension;

    while(scan)
    {
        if(!extension.empty())
        {
            filename.append(".");
            filename.append(extension);
        }

        extension = scan.take_while(!match_chars("."));

        scan++;
    }

    std::cout << "\n" << s << " ->\nfilename: " << filename << "\nextension: " << extension << std::endl;

    return 0;
}
