#pragma once
#include "pch.h"
#include "HelperFunctions.h"

// From Frank D. Luna: 3D Game Programming with DirectX12


	unsigned  int CalcConstantBufferByteSize(unsigned int bytesize) {


		return (bytesize + 255) & ~255;
	}
	

	void readfile(char const* fn, std::vector<char> &vbytes)
	{
		std::ifstream inputstream(fn, std::ios::binary);
		std::ios_base::iostate state = inputstream.rdstate();
		bool isbad = inputstream.bad();
		bool isgood = inputstream.good();
		bool isfail = inputstream.fail();
		inputstream.seekg(0, std::ios::end);
		std::ifstream::pos_type pos = inputstream.tellg();
		vbytes.resize(pos);

		inputstream.seekg(0, std::ios::beg);
		inputstream.read((char*) &vbytes[0], pos);

		
	}

	//Funci�n auxiliar para generar un vector random normalizado
	XMVECTOR RandomVector()
	{
		XMVECTOR a = XMVECTOR{ RandomNumber(-1, 1), RandomNumber(-1, 1), RandomNumber(-1, 1) };
		a = XMPlaneNormalize(a);
		return a;
	}

	//Funci�n auxiliar para generar un float random
	float RandomNumber(float Min, float Max)
	{
		return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	}