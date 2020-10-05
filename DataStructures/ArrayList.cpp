#include <iostream>
#include "ArrayList.h"


template <class T>
ArrayList<T>::ArrayList() {
	data = new T[5];
	arrlength = 5;
	listsize = 0;
}

template <class T>
bool ArrayList<T>::needtoresize() {
	return listsize == arrlength;
}

template <class T>
void ArrayList<T>::resize() {
	T* temp = new T[arrlength * 2];
	for (int i = 0; i < listsize; i++) {
		temp[i] = data[i];
	}

	data = temp;
	arrlength *= 2;
}

template <class T>
bool ArrayList<T>::contains(T item) {
	return indexof(item) > -1;
}

template <class T>
T* ArrayList<T>::get(int index) {
	if (index >= 0 && index < arrlength) {
		return &data[index];
	}

	return NULL;
}

template <class T>
void ArrayList<T>::add(T item) {
	if (needtoresize()) {
		resize();
	}

	data[listsize] = item;
	listsize++;
}

template <class T>
void ArrayList<T>::add(int index, T item) {
	if (index >= 0 && index < arrlength) {
		if (needtoresize()) {
			resize();
		}

		for (int i = listsize; i <= index; i--) {
			data[i + 1] = data[i];
		}

		data[index] = item;
		listsize++;
	}
}

template <class T>
void ArrayList<T>::remove(int index) {
	for (int i = index; i < listsize; i++) {
		data[i] = data[i + 1];
	}

	listsize--;
}

template <class T>
void ArrayList<T>::set(int index, T item) {
	if (index >= 0 && index < arrlength) {
		data[index] = item;
	}
}

template <class T>
int ArrayList<T>::indexof(T item) {
	for (int i = 0; i <= listsize; i++) {
		if (item == data[i]) {
			return i;
		}
	}

	return -1;
}

template <class T>
int ArrayList<T>::lastindexof(T item) {
	for (int i = listsize; i >= 0; i--) {
		if (item == data[i]) {
			return i;
		}
	}

	return -1;
}

template <class T>
int ArrayList<T>::size() {
	return listsize;
}
