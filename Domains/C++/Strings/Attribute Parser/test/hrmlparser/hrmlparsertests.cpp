#include <gtest/gtest.h>

#include "../../include/hrmlelement.h"
#include "../../include/hrmlattribute.h"
#include "../../include/hrmlparser.h"

/*
g++ -std=c++14 -isystem ./third_party/googletest/googletest/include -isystem ./include/ -pthread ./test/main.cpp ./src/hrmlparser.cpp ./src/hrmlelement.cpp ./src/hrmlattribute.cpp ./test/hrmlparser/hrmlparsertests.cpp ./lib/googletest/libgtest.a -o ./bin/test/hrmlparser/hrmlparsertests

./bin/test/hrmlparser/hrmlparsertests
*/

TEST(test_hrmlparser, getName_element_constist_of_just_tag_name)
{
    // Arrange
    string line = "tag1";

    HrmlParser parser({ line });

    // Act
    auto name = parser.getName(line);

    // Assert
    EXPECT_EQ("tag1", name);
}

TEST(test_hrmlparser, getName_element_constist_of_tag_name_and_attributes)
{
    // Arrange
    string line = "tag1 attr1 = val1 attr2 = val2";

    HrmlParser parser({ line });

    // Act
    auto name = parser.getName(line);

    // Assert
    EXPECT_EQ("tag1", name);
}

TEST(test_hrmlparser, getAttribute_element_has_one_attributes)
{
    // Arrange
    string line = "attr1 = \"val1\"";

    HrmlParser parser({ line });

    // Act
    auto attribute = parser.getAttribute(line);

    // Assert
    EXPECT_EQ("attr1", attribute.getName());
    EXPECT_EQ("val1", attribute.getValue());
}

TEST(test_hrmlparser, getAttribute_element_has_more_attributes)
{
    // Arrange
    string line = "attr1 = \"val1\" attr2 = \"val2\"";

    HrmlParser parser({ line });

    // Act
    auto attribute = parser.getAttribute(line);

    // Assert
    EXPECT_EQ("attr1", attribute.getName());
    EXPECT_EQ("val1", attribute.getValue());
}
TEST(test_hrmlparser, getAttributes_element_has_no_attributes)
{
    // Arrange
    string line = "";

    HrmlParser parser({ line });

    // Act
    auto attributes = parser.getAttributes(line);

    // Assert
    EXPECT_EQ(0, attributes.size());
}

TEST(test_hrmlparser, getAttributes_element_has_one_attributes)
{
    // Arrange
    string line = "attr1 = \"val1\"";

    HrmlParser parser({ line });

    // Act
    auto attributes = parser.getAttributes(line);

    // Assert
    auto first_attr = attributes.front();
    EXPECT_EQ("attr1", first_attr.getName());
    EXPECT_EQ("val1", first_attr.getValue());
}

TEST(test_hrmlparser, getAttributes_element_has_more_attributes)
{
    // Arrange
    string line = "attr1 = \"val1\" attr2 = \"val2\"";

    HrmlParser parser({ line });

    // Act
    auto attributes = parser.getAttributes(line);

    // Assert
    auto first_attr = attributes.front();
    EXPECT_EQ("attr1", first_attr.getName());
    EXPECT_EQ("val1", first_attr.getValue());

    auto last_attr = attributes.back();
    EXPECT_EQ("attr2", last_attr.getName());
    EXPECT_EQ("val2", last_attr.getValue());
}

TEST(test_hrmlparser, parseStartingTag_element_has_no_attributes)
{
    // Arrange
    string line = "tag1";

    HrmlParser parser({ line });

    // Act
    auto element = parser.parseStartingTag(line);

    // Assert
    EXPECT_EQ("tag1", element->getTagName());
    EXPECT_EQ(0, element->getAttributes().size());
}

TEST(test_hrmlparser, parseStartingTag_element_has_more_attributes)
{
    // Arrange
    string line = "tag1 attr1 = \"val1\" attr2 = \"val2\"";

    HrmlParser parser({ line });

    // Act
    auto element = parser.parseStartingTag(line);

    // Assert
    EXPECT_EQ("tag1", element->getTagName());
    EXPECT_EQ(2, element->getAttributes().size());

    auto first_attr = element->getAttributes().front();
    EXPECT_EQ("attr1", first_attr.getName());
    EXPECT_EQ("val1", first_attr.getValue());

    auto last_attr = element->getAttributes().back();
    EXPECT_EQ("attr2", last_attr.getName());
    EXPECT_EQ("val2", last_attr.getValue());
}

TEST(test_hrmlparser, parseEndingTag)
{
    // Arrange
    string line = "/tag1";

    HrmlParser parser({ line });

    // Act
    auto tagName = parser.parseEndingTag(line);

    // Assert
    EXPECT_EQ("tag1", tagName);
}

TEST(test_hrmlparser, parse_one_element)
{
    // Arrange
    string startingTag = "<tag1 attr1 = \"val1\" attr2 = \"val2\">";
    string endingTag = "</tag1>";

    HrmlParser parser({ startingTag, endingTag });

    // Act
    auto elements = parser.parse();

    // Assert
    EXPECT_EQ(1, elements.size());
}

TEST(test_hrmlparser, parse_not_nested_elements)
{
    // Arrange
    string startingTag1 = "<tag1 attr1 = \"val1\" attr2 = \"val2\">";
    string endingTag1 = "</tag1>";
    string startingTag2 = "<tag2 attr1 = \"val1\" attr2 = \"val2\">";
    string endingTag2 = "</tag2>";

    HrmlParser parser({ startingTag1, endingTag1, startingTag2, endingTag2 });

    // Act
    auto elements = parser.parse();

    // Assert
    EXPECT_EQ(2, elements.size());
}

TEST(test_hrmlparser, parse_nested_elements)
{
    // Arrange
    string startingTag1 = "<tag1 attr1 = \"val1\" attr2 = \"val2\">";
    string startingTag2 = "<tag2 attr1 = \"val1\" attr2 = \"val2\">";
    string endingTag2 = "</tag2>";
    string endingTag1 = "</tag1>";

    HrmlParser parser({ startingTag1, startingTag2, endingTag2, endingTag1 });

    // Act
    auto elements = parser.parse();

    // Assert
    EXPECT_EQ(1, elements.size());
}