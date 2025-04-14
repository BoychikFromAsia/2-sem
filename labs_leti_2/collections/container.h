#pragma once

template <typename T>
struct Container {
	T data;
	Container* next;

	Container() : next(nullptr) {}

	Container(const T& data) : data(data), next(nullptr) {}
};