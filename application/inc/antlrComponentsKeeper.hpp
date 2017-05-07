#pragma once

#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include <forward_list>

#include "antlr4-runtime.h"
#include "JavaLexer.h"
#include "JavaParser.h"


namespace JWB {	namespace details {

/// @class AntlrComponentsKeeper
/// @brief It takes the path entered by the user, creates the antlr components and stores them internally
/// 	   Used by calculators for access to parse trees and tokenStreams

class AntlrComponentsKeeper
{
public:
	AntlrComponentsKeeper() = delete;
	AntlrComponentsKeeper(AntlrComponentsKeeper const&) = delete;
	AntlrComponentsKeeper(AntlrComponentsKeeper&&) = delete;
	AntlrComponentsKeeper& operator=(AntlrComponentsKeeper const&) = delete;
	AntlrComponentsKeeper& operator=(AntlrComponentsKeeper&&) = delete;

	AntlrComponentsKeeper(std::string const &stringPath);
	std::vector<antlr4::tree::ParseTree*> const& getTrees() const;
	std::vector<antlr4::CommonTokenStream*> const& getTokens() const;

private:
	std::vector<antlr4::tree::ParseTree*> trees;
	std::vector<antlr4::CommonTokenStream*> tokens;
	boost::filesystem::ifstream stream;

	struct AntlrComponents
	{
		AntlrComponents(
			boost::filesystem::ifstream &stream,
			std::vector<antlr4::tree::ParseTree*> &trees,
			std::vector<antlr4::CommonTokenStream*> &tokens
		);

		antlr4::ANTLRInputStream inputStream;
		JavaLexer lexer;
		antlr4::CommonTokenStream tokenStream;
		JavaParser parser;
	};

	std::forward_list<AntlrComponents> antlrComponents;
};

}}
