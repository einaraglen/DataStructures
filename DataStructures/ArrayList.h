#pragma once

template <class T>
class ArrayList {
private:
	T* data;
	int arrlength;
	int listsize;
	void resize();
	bool needtoresize();

public:
	ArrayList();
	bool contains(T item);
	void add(T item);
	void add(int index, T item);
	void set(int index, T item);
	int indexof(T item);
	int lastindexof(T item);
	void remove(int index);
	T* get(int index);
	int size();
};

