#pragma once
#ifndef RED_BLACK_NODE_
#define RED_BLACK_NODE_

#define RED true
#define BLACK false

template<class ItemType>
class rbNode {
private:
	ItemType item; // Data portion
	rbNode<ItemType>* leftChildPtr; // Pointer to left child
	rbNode<ItemType>* rightChildPtr; // Pointer to right child

	rbNode<ItemType>* parentPtr;

	bool color;
public:
	rbNode(const ItemType& anItem);

	ItemType getItem() const;
	void setItem(const ItemType& anItem);

	rbNode<ItemType>* getLeftChildPtr() const;
	rbNode<ItemType>* getRightChildPtr() const;
	rbNode<ItemType>* getParentPtr() const;

	void setLeftChildPtr(rbNode<ItemType>* leftPtr);
	void setRightChildPtr(rbNode<ItemType>* rightPtr);
	void setParentPtr(rbNode<ItemType>* parentPtr);



	bool getColor() const;
	void setColor(const bool newColor);
	void flipColor();
}; // end rbNode

template<class ItemType>
rbNode<ItemType>::rbNode(const ItemType& anItem) : item(anItem), leftChildPtr(nullptr),
rightChildPtr(nullptr), parentPtr(nullptr), color(RED) {
}

template<class ItemType>
ItemType rbNode<ItemType>::getItem() const {
	return item;
}

template<class ItemType>
void rbNode<ItemType>::setItem(const ItemType& anItem) {
	item = anItem;
}

template<class ItemType>
rbNode<ItemType>* rbNode<ItemType>::getLeftChildPtr() const {
	return leftChildPtr;
}

template<class ItemType>
rbNode<ItemType>* rbNode<ItemType>::getRightChildPtr() const {
	return rightChildPtr;
}

template<class ItemType>
rbNode<ItemType>* rbNode<ItemType>::getParentPtr() const {
	return parentPtr;
}

template<class ItemType>
void rbNode<ItemType>::setLeftChildPtr(rbNode<ItemType>* leftPtr) {
	leftChildPtr = leftPtr;
}

template<class ItemType>
void rbNode<ItemType>::setRightChildPtr(rbNode<ItemType>* rightPtr) {
	rightChildPtr = rightPtr;
}

template<class ItemType>
void rbNode<ItemType>::setParentPtr(rbNode<ItemType>* parent) {
	parentPtr = parent;
}

template<class ItemType>
bool rbNode<ItemType>::getColor() const {
	return color;
}

template<class ItemType>
void rbNode<ItemType>::setColor(const bool newColor) {
	color = newColor;
}

template<class ItemType>
void rbNode<ItemType>::flipColor() {
	if (color == RED) {
		color = BLACK;
		return;
	}

	color = RED;
}

#endif