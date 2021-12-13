#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>

//Function Template Declaration

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B>& p);


template<typename A, typename B, typename C>
std::multimap<B, A, std::greater<int>> flip_map(const std::map<A, B, C>& src);


//Function Template Implementation

template<typename A, typename B> 
std::pair<B, A> flip_pair(const std::pair<A, B>& p)
{
	return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B, typename C>
std::multimap < B, A, std:: greater<int >> flip_map(const std::map<A, B, C>& src)
{
	std::multimap<B, A, std::greater<int>> dst;
	std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
		flip_pair<A, B>);
	return dst;
}
