#pragma once

#include "node.h"

#include <iostream>
#include <memory>
#include <map>

std::shared_ptr<Node> ParseCondition(std::istream& is);
