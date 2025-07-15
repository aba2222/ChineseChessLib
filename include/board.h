#pragma once

#include <vector>
#include <string>
#include <utility>
#include <tuple>

using Pos = std::pair<int, int>;
using Move = std::tuple<bool, int, int>;  // (�Ƿ����, xƫ��, yƫ��)

struct Chess {
	int x, y;  // ����λ��
	std::wstring name;
	std::string color;  // ������ɫ��"#000000"Ϊ��ɫ��"#FF0000"Ϊ��ɫ
};

using Board = std::vector<std::vector<Chess*>>;