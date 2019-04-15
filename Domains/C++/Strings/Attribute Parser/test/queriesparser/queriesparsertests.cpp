#include <gtest/gtest.h>

#include "../../include/elementquery.h"
#include "../../include/attributequery.h"
#include "../../include/queriesparser.h"

/*
g++ -std=c++14 -isystem ./third_party/googletest/googletest/include -isystem ./include/ -pthread ./test/main.cpp ./src/queriesparser.cpp ./src/query.cpp ./src/elementquery.cpp ./src/attributequery.cpp ./src/hrmlelement.cpp ./src/hrmlattribute.cpp ./test/queriesparser/queriesparsertests.cpp ./lib/googletest/libgtest.a -o ./bin/test/queriesparser/queriesparsertests

./bin/test/queriesparser/queriesparsertests
*/

TEST(Test_QueriesParser, Parse_OneQuery_OneElementWithoutAttribute)
{
    // Arrange
    string query1 = "tag1";

    QueriesParser parser({ query1 });

    // Act
    auto queries = parser.parse();

    // Assert
    EXPECT_EQ(1, queries.size());
    EXPECT_EQ(nullptr, dynamic_cast<ElementQuery*>(queries.front().get()));
    EXPECT_EQ(nullptr, dynamic_cast<AttributeQuery*>(queries.front().get()));
}

TEST(Test_QueriesParser, Parse_OneQuery_OneElementWithAttribute)
{
    // Arrange
    string query1 = "tag1~attr1";

    QueriesParser parser({ query1 });

    // Act
    auto queries = parser.parse();

    // Assert
    EXPECT_EQ(1, queries.size());
    EXPECT_EQ(nullptr, dynamic_cast<AttributeQuery*>(queries.front().get()));
    EXPECT_NE(nullptr, dynamic_cast<ElementQuery*>(queries.front().get()));
}

TEST(Test_QueriesParser, Parse_OneQuery_MoreThanOneElementWithAttribute)
{
    // Arrange
    string query1 = "tag3.tag2.tag1~attr1";

    QueriesParser parser({ query1 });

    // Act
    auto queries = parser.parse();

    // Assert
    EXPECT_EQ(1, queries.size());
    EXPECT_EQ(nullptr, dynamic_cast<AttributeQuery*>(queries.front().get()));
    EXPECT_NE(nullptr, dynamic_cast<ElementQuery*>(queries.front().get()));
}

TEST(Test_QueriesParser, Parse_OneQuery_MoreThanOneElementWithoutAttribute)
{
    // Arrange
    string query1 = "tag3.tag2.tag1";

    QueriesParser parser({ query1 });

    // Act
    auto queries = parser.parse();

    // Assert
    EXPECT_EQ(1, queries.size());
    EXPECT_EQ(nullptr, dynamic_cast<ElementQuery*>(queries.front().get()));
    EXPECT_EQ(nullptr, dynamic_cast<AttributeQuery*>(queries.front().get()));
}

TEST(Test_QueriesParser, Parse_MoreThanOneQuery)
{
    // Arrange
    string query1 = "tag1~attr1";
    string query2 = "tag2.tag1~attr1";

    QueriesParser parser({ query1, query2 });

    // Act
    auto queries = parser.parse();

    // Assert
    EXPECT_EQ(2, queries.size());
    EXPECT_NE(nullptr, dynamic_cast<ElementQuery*>(queries.front().get()));
    EXPECT_NE(nullptr, dynamic_cast<ElementQuery*>(queries.back().get()));
}