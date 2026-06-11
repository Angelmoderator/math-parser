#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "tokenizer.h"






// REQUIRE — провал останавливает тест, 
// CHECK — провал отмечается,TEST_CASE("Tokenizer base logic", "[tokenizer]") {
  TEST_CASE("Tokenizer base logic", "[tokenizer]") {
    SECTION("Simple expression with multiple additions") {
        auto t = tokenize("3+4+2");
        REQUIRE(t.size() == 5);
        
        CHECK(t[0].type == TokenType::Number);
        CHECK(t[0].value == 3.0);
        
        CHECK(t[1].type == TokenType::Operator);
        CHECK(t[1].op == '+');
        
        CHECK(t[2].type == TokenType::Number);
        CHECK(t[2].value == 4.0);
        
        CHECK(t[3].type == TokenType::Operator);
        CHECK(t[3].op == '+');
        
        CHECK(t[4].type == TokenType::Number);
        CHECK(t[4].value == 2.0);
    }

    SECTION("Floating point and multiple operator types") {
        auto t = tokenize("12.5+3/2");
        REQUIRE(t.size() == 5);
        
        CHECK(t[0].type == TokenType::Number);
        CHECK(t[0].value == 12.5);
        
        CHECK(t[1].type == TokenType::Operator);
        CHECK(t[1].op == '+');
        
        CHECK(t[2].type == TokenType::Number);
        CHECK(t[2].value == 3.0);
        
        CHECK(t[3].type == TokenType::Operator);
        CHECK(t[3].op == '/');
        
        CHECK(t[4].type == TokenType::Number);
        CHECK(t[4].value == 2.0);
    }

    SECTION("Basic binary operation") {
        auto t = tokenize("7+8");
        REQUIRE(t.size() == 3);
        
        CHECK(t[0].type == TokenType::Number);
        CHECK(t[0].value == 7.0);
        
        CHECK(t[1].type == TokenType::Operator);
        CHECK(t[1].op == '+');
        
        CHECK(t[2].type == TokenType::Number);
        CHECK(t[2].value == 8.0);
    }
    
    SECTION("Parentheses handling") {
        // В твоем enum есть LParen и RParen, стоит проверить и их
        auto t = tokenize("(3)");
        REQUIRE(t.size() == 3);
        
        CHECK(t[0].type == TokenType::LParen);
        CHECK(t[1].type == TokenType::Number);
        CHECK(t[1].value == 3.0);
        
        CHECK(t[2].type == TokenType::RParen);
    }
    SECTION("Extra spaces"){
        auto t = tokenize(" 3.15  +  2  ");
        REQUIRE(t.size() == 3);

        CHECK(t[0].value == Catch::Approx(3.15));

        CHECK(t[1].type == TokenType::Operator);
        CHECK(t[1].op == '+');

        CHECK(t[2].type == TokenType::Number);
        CHECK(t[2].value == 2.0);
    }
}
