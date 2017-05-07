#include "antlrComponentsKeeper.hpp"
#include "antlr4-runtime.h"

namespace fs = boost::filesystem;
using namespace antlr4;

using std::cerr;
using std::endl;
using std::vector;
using std::cout;
using std::invalid_argument;

namespace JWB {	namespace details {

AntlrComponentsKeeper::AntlrComponentsKeeper(std::string const &stringPath)
{
	fs::path pathToProject(stringPath);

	if (!exists(pathToProject))
		throw invalid_argument(pathToProject.string() + " path does not exist");

	if (is_regular_file(pathToProject))
	{
		stream.open(pathToProject);
		antlrComponents.emplace_front(stream, trees, tokens);
		stream.close();

	}
	else if (is_directory(pathToProject))
	{
		for (fs::directory_entry& e : fs::recursive_directory_iterator(pathToProject))
		{
			if (!is_regular_file(e) || e.path().extension().string() != ".java")
				continue;

			stream.open(e);
			antlrComponents.emplace_front(stream, trees, tokens);
			stream.close();
		}
	}
	else
	{
		throw invalid_argument("Path exists, but it's not a regular file or directory");
	}
}

std::vector<antlr4::tree::ParseTree*> const& AntlrComponentsKeeper::getTrees() const
{
	return trees;
}

std::vector<antlr4::CommonTokenStream*> const& AntlrComponentsKeeper::getTokens() const
{
	return tokens;
}

AntlrComponentsKeeper::AntlrComponents::AntlrComponents(
	fs::ifstream &stream,
	vector<antlr4::tree::ParseTree*> &trees,
	vector<antlr4::CommonTokenStream*> &tokens
) :
	inputStream(stream),
	lexer(&inputStream),
	tokenStream(&lexer),
	parser(&tokenStream)
{
	trees.push_back(parser.compilationUnit());
	tokens.push_back(&tokenStream);
}

}}
