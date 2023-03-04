# Contributing to Wase Engine
This document will contain all the information for you to get started on contributing to Wase ECS.

[documentation]: https://wase-ecs.com/documentation
[repo]: https://github.com/Wase-ECS/wase-ecs
[issues]: https://github.com/Wase-ECS/wase-ecs/issues
[new_issue]: https://github.com/Wase-ECS/wase-ecs/issues/new/choose
[email]: info@wase-ecs.com

## Issues
If you want to do a feature request or report a bug you can [create a new issue](https://github.com/Wase-ECS/wase-ecs/issues/new) by selecting a template and filling this in with as much information as possible.

## Documentation
The documentation for Wase ECS is written in Markdown in the [wase-ecs-docs repository](https://github.com/Wase-ECS/wase-ecs-docs). The README.md of this repository contains the information you will need to start writing documentation. This repository has a production branch that will automatically deploy to the [Wase ECS website](https://wase-ecs.com/).

## C++ style
```c++
// Use #pragma once instead of #ifndef
#pragma once

// First STL
#include <iostream>
#include <string>

// Second Wase-ECS source code
#include <entity.h> // Use angle brackets

// Namespaces should always start with wase::ecs
// Use nested namespaces
namespace wase::ecs::folder
{ // Braces are always put on the next line
    class Example
    {
    // For classes always follow the rule of five (https://en.cppreference.com/w/cpp/language/rule_of_three)
    // Order access specifiers like the following:
    public:
        // For every access specifier we keep an order in defining things
        // 1. Declare constructors and destructors
        // 2. Declare all our methods
        // 3. Declare variables

        // Use lowerCamelCase for method names
        int getPlayerScore() const; // If possible mark by const
        /**
         * Use JavaDoc style comments
         *
         * @param score: amount of score
         **/
        void setPlayerScore(const int score); // If possible mark parameters by const
    protected:
    private:
        // Prefix static variables with s_ and start the name with a capital letter
        static int s_CombinedScores = 0;
      
        // Prefix member variables with m_ and start the name with a capital letter
        int m_PlayerScore = 0;
    };
}

// Use typename when using templates
template<typename T>

// Use UPPERCASE for enums
enum Priority
{
    LOW,
    NORMAL,
    HIGH
};
```