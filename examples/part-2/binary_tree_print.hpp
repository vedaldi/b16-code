#ifndef __binary_tree_print__
#define __binary_tree_print__

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace details
{
template <typename T>
std::vector<std::string> _print_binary_tree_recursive(const T& tree)
{
    using std::max;
    using std::string;
    if (!tree) return {};
    auto text = (std::ostringstream{} << value(tree)).str();

    auto llines = _print_binary_tree_recursive(left(tree));
    auto rlines = _print_binary_tree_recursive(right(tree));

    const auto lwidth = llines.empty() ? 0 : llines.front().size();
    const auto rwidth = rlines.empty() ? 0 : rlines.front().size();

    const auto n = max(llines.size(), rlines.size());
    llines.resize(n, string(lwidth, ' '));
    rlines.resize(n, string(rwidth, ' '));

    const auto lwidthp = max(text.size() + 2, lwidth);
    const auto pad = string(lwidthp - lwidth, ' ');
    text += string{" "} + string(lwidthp - text.size() - 1, rwidth ? '-' : ' ');
    if (rwidth) {
        text += "v" + string(rwidth - 1, ' ');
    }

    std::vector<string> lines = {text};
    const auto concat = [&](const string& a, const string& b) { return a + pad + b; };
    std::transform(llines.begin(), llines.end(), rlines.begin(), std::back_inserter(lines), concat);

    return lines;
}
}  // namespace details

// Print a binary tree
template <typename T>
void print_binary_tree(const T& tree)
{
    auto lines = details::_print_binary_tree_recursive(tree);
    for (const auto& line : lines) {
        std::cout << line << '\n';
    }
}

#endif