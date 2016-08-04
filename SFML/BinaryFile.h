#pragma once
#include <iostream>
#include <fstream>
#include "BinaryFilesStructs.h"

using namespace std;

template<class typeHead, class typeBody>class BinaryFile
{
public:
	BinaryFile(string fileName);
	~BinaryFile();

	int getBodySize();
	typeHead getHead();
	typeBody getBody(int bodyNumber);
	void setHead(typeHead newHead);
	void setBody(typeBody newBody, int bodyNumber);
	void addBody(typeBody newBody);
	void removeBody(int bodyNumber);
	void save();

private:
	string fileName;
	typeHead *head;
	vector <typeBody*> body;
};





//     DEFINITIONS


template<class typeHead, class typeBody> BinaryFile<typeHead, typeBody>::BinaryFile(string fileName)
{
	BinaryFile::fileName = fileName;
	ifstream file(fileName, ios::binary);
	file.seekg(0);

	//set bodySize
	char* temp = new char[sizeof(Header)];
	file.read(temp, sizeof(Header));
	Header *header = (Header*)temp;
	int bodySize = header->number;
	delete temp;

	//read head
	file.seekg(0);
	char* hTemp = new char[sizeof(typeHead)];
	file.read(hTemp, sizeof(typeHead));
	head = (typeHead*)hTemp;

	//read body
	for (int i = 0; i < bodySize; i++)
	{
		char* bTemp = new char[sizeof(typeBody)];
		file.read(bTemp, sizeof(typeBody));
		body.push_back((typeBody*)bTemp);
	}

}


template<class typeHead, class typeBody>BinaryFile<typeHead, typeBody>::~BinaryFile()
{
	delete head;
	for ( unsigned int i = 0; i < body.size(); i++)
	{
		delete body[i];
	}
}


template<class typeHead, class typeBody>int BinaryFile<typeHead, typeBody>::getBodySize()
{
	return body.size();
}


template<class typeHead, class typeBody>typeHead BinaryFile<typeHead, typeBody>::getHead()
{
	return *head;
}


template<class typeHead, class typeBody>typeBody BinaryFile<typeHead, typeBody>::getBody(int bodyNumber)
{
	return *body[bodyNumber];
}


template<class typeHead, class typeBody>void BinaryFile<typeHead, typeBody>::setHead(typeHead newHead)
{
	*head = newHead;
}


template<class typeHead, class typeBody>void BinaryFile<typeHead, typeBody>::setBody(typeBody newBody, int bodyNumber)
{
	*body[bodyNumber] = newBody;
}


template<class typeHead, class typeBody>void BinaryFile<typeHead, typeBody>::addBody(typeBody newBody)
{
	int size = body.size();
	body.push_back(new typeBody);
	*body[size] = newBody;
}


template<class typeHead, class typeBody>void BinaryFile<typeHead, typeBody>::removeBody(int bodyNumber)
{
	body.erase(body.begin() + bodyNumber);
}


template<class typeHead, class typeBody>void BinaryFile<typeHead, typeBody>::save()
{
	ofstream file(fileName, ios::binary);
	file.seekp(0);
	Header *header = (Header*)head;
	header->number = body.size();
	file.write((char*)head, sizeof(typeBody));
	
	
	for (int i = 0; i < (signed)body.size(); i++)
	{
		file.write((char*)body[i], sizeof(typeBody));
	}
}