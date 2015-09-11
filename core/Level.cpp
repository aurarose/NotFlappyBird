#include "Level.h"
#include "Globals.h"

// Load a level from a file specified by path
void Level::loadFromFile(string path){
	
	ifstream ifile(path);
	string line;
	g_cur_id = 0;

	while (getline(ifile, line)){
		
		// Trim leading and trailing whitespace
		if (line.find_first_not_of('\t')!=string::npos&&
			line.find_last_not_of('\t') != string::npos)
		line = line.substr(line.find_first_not_of('\t'),line.find_last_not_of('\t'));

		// If not object data skip
		if (line.find("object id") == string::npos) continue;

		int length = line.find("gid=")-line.find("type=");
		string type = "";
		if (line.find("type=")!=string::npos) type = line.substr(line.find("type=")+6,length-8);
		
	}
	g_cur_id = this->cur_id;
}