#pragma once

#include<iostream>

using namespace std;

class Animal
{
public:
	// ������̳в�ʵ��
	virtual void voice() = 0;

	Animal();  // ���캯��

	
	// ע�⣺���д�� ������������ ����ô��Ҫдһ�� .cpp �ļ���ʵ��

	virtual ~Animal(); // ���������������ʵ�����г���������������Ҫ�ͷţ���ô�ڸ����о�Ҫʹ�ã�
	                   // �����ſ���ʹ�ö�̬����
};


