#include<iostream>
#include<fstream>
#include<ctime>
#include<Windows.h>
#include <immintrin.h>
#include <intrin.h>
#include<cerrno>
#include<string>
#include<sstream>
#include <emmintrin.h>
#include <immintrin.h>
using namespace std;
double time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0, time7 = 0;
void chuanx() {
	ifstream ifs("C://Users//86183//Desktop//����Ԫ��.txt");//�ļ��Ķ���
	ifstream if1("C://Users//86183//Desktop//��Ԫ��.txt");
	ofstream out("C://Users//86183//Desktop//��Ԫ���.txt");

	int forline = 8;//����Ԫ��8��
	int line = 22;//��Ԫ��22��
	int artix = 130;//ÿһ����130��Ԫ��

	int xiaoyuanzi[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanzi[i][j] = 0;
		}
	}



	int xiaoyuanhang[8][130];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanhang[i][j] = 0;
		}
	}
	//��Ԫ�������



	int Result[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Result[i][j] = 0;
		}
	}

	string s;
	int temp1 = 0;
	for (int i = 1; i <= 22; i++) {
		getline(if1, s);
		stringstream ss(s);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//ÿһ�е�һ��Ԫ��Ϊ���б�ţ�ͬһ����Ӧλ��Ϊ1
		}
		temp1 = 0;
	}
	//��Ԫ�Ӷ���


	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//��Ԫ�ӵĶ���


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//������Ԫ
	int T = 0;
	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j>=0; j--) {
			if (xiaoyuanhang[t][j] == 1) {//����1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) {//������Ԫ��
					for (int k =0; k < 130; k++) {
						xiaoyuanzi[j][k] = xiaoyuanhang[t][k];
						Result[j][k] = xiaoyuanhang[t][k];
					}
					t++;
					//cout << "easeasd" << result[j][j] << " " << j << endl;
					//cout << t << endl;
					break;
				}
				else {
					for (int k =0; k < 130; k++) {
						if (xiaoyuanzi[j][k] == xiaoyuanhang[t][k]) {
							xiaoyuanhang[t][k] = 0;
						}
						else {
							xiaoyuanhang[t][k] = 1;
						}
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0��ȫ0������Ԫ����
			t++;
		}
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	time1 += (tail3 - head3) * 1000.0 / freq3;
	/*cout << "��˹��Ԫ�����㷨���л�����ʱ��Ϊ " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;


	int temp2 = 0;
	for (int i = 129; i >= 0; i--)
	{
		for (int j = 129; j >= 0; j--) {
			if (Result[i][j] == 1) {
				cout << j << " ";
				temp2 = 1;
			}
			if (j == 0 && temp2 == 1) {
				cout << endl;
				temp2 = 0;
			}
		}
	}*/

	ifs.close();
}
void SSE1() {
	ifstream ifs("C://Users//86183//Desktop//����Ԫ��.txt");//�ļ��Ķ���
	ifstream if1("C://Users//86183//Desktop//��Ԫ��.txt");
	ofstream out("C://Users//86183//Desktop//��Ԫ���.txt");

	int forline = 8;//����Ԫ��8��
	int line = 22;//��Ԫ��22��
	int artix = 130;//ÿһ����130��Ԫ��

	int xiaoyuanzi[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanzi[i][j] = 0;
		}
	}



	int xiaoyuanhang[8][130];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanhang[i][j] = 0;
		}
	}
	//��Ԫ�������



	int Result[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Result[i][j] = 0;
		}
	}

	string s;
	int temp1 = 0;
	for (int i = 1; i <= 22; i++) {
		getline(if1, s);
		stringstream ss(s);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//ÿһ�е�һ��Ԫ��Ϊ���б�ţ�ͬһ����Ӧλ��Ϊ1
		}
		temp1 = 0;
	}
	//��Ԫ�Ӷ���


	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//��Ԫ�ӵĶ���

	
	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	//int t = 0;//������Ԫ
	//int T = 0;
	//while (true) {
	//	if (t == 8) {
	//		break;
	//	}
	//	for (int j = 129; j>=0; j--) {
	//		if (xiaoyuanhang[t][j] == 1) {//����1
	//			T = 1;
	//			if (xiaoyuanzi[j][j] == 0) {//������Ԫ��
	//				for (int k =0; k < 130; k++) {
	//					xiaoyuanzi[j][k] = xiaoyuanhang[t][k];
	//					Result[j][k] = xiaoyuanhang[t][k];
	//				}
	//				t++;
	//				//cout << "easeasd" << result[j][j] << " " << j << endl;
	//				//cout << t << endl;
	//				break;
	//			}
	//			else {
	//				for (int k =0; k < 130; k++) {
	//					if (xiaoyuanzi[j][k] == xiaoyuanhang[t][k]) {
	//						xiaoyuanhang[t][k] = 0;
	//					}
	//					else {
	//						xiaoyuanhang[t][k] = 1;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	if (T == 1) {
	//		T = 0;
	//	}
	//	else {
	//		//t=0��ȫ0������Ԫ����
	//		t++;
	//	}
	//}
	// 
	// 
	// 
	// end time




	int t = 0;//������Ԫ
	int T = 0;

	//__m128i ones = _mm_set1_epi32(1); // ��ʼ��һ��ȫΪ1������

	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //����1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //������Ԫ��
					for (int k = 0; k+4 < 130; k += 4) { // 4��Ԫ��һ�����SSE��������
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��4��Ԫ��װ�ص�һ��SSE������
						_mm_storeu_si128((__m128i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // ��SSE�����Ľ���洢��xiaoyuanzi��4��Ԫ����
						_mm_storeu_si128((__m128i*) & Result[j][k], vec_xiaoyuanhang); // ��SSE�����Ľ���洢��Result��4��Ԫ����
					}
					t++;
					break;
				}
				//else {
				//	for (int k = 0; k + 4 < 130; k += 4) { // 4��Ԫ��һ�����SSE��������
				//		__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // ��xiaoyuanzi��4��Ԫ��װ�ص�һ��SSE������
				//		__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��4��Ԫ��װ�ص�һ��SSE������
				//		vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // ��xiaoyuanhang�ж�Ӧλ��Ϊ0��Ԫ�ر�Ϊ1
				//		_mm_storeu_si128((__m128i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // ��SSE�����Ľ���洢��xiaoyuanhang��4��Ԫ����
				//	}
				//}


				else {
					for (int k = 0; k < 130; k++) {
						if (xiaoyuanzi[j][k] == xiaoyuanhang[t][k]) {
							xiaoyuanhang[t][k] = 0;
						}
						else {
							xiaoyuanhang[t][k] = 1;
						}
					}
				}


			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0��ȫ0������Ԫ����
			t++;
		}
	}





	//__m256i ones = _mm256_set1_epi32(1); // ��ʼ��һ��ȫΪ1������

	//while (true) {
	//	if (t == 8) {
	//		break;
	//	}
	//	for (int j = 129; j >= 0; j--) {
	//		if (xiaoyuanhang[t][j] == 1) { //����1
	//			T = 1;
	//			if (xiaoyuanzi[j][j] == 0) { //������Ԫ��
	//				for (int k = 0; k + 8 < 130; k += 8) { // 8��Ԫ��һ�����AVX��������
	//					__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��8��Ԫ��װ�ص�һ��AVX������
	//					_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��xiaoyuanzi��8��Ԫ����
	//					_mm256_storeu_si256((__m256i*) & Result[j][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��Result��8��Ԫ����
	//				}
	//				t++;
	//				break;
	//			}
	//			else {
	//				for (int k = 0; k < 130; k++) {
	//					if (xiaoyuanzi[j][k] == xiaoyuanhang[t][k]) {
	//						xiaoyuanhang[t][k] = 0;
	//					}
	//					else {
	//						xiaoyuanhang[t][k] = 1;
	//					}
	//				}
	//			}
	//			//else {
	//			//	for (int k = 0; k + 8 < 130; k += 8) { // 8��Ԫ��һ�����AVX��������
	//			//		__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // ��xiaoyuanzi��8��Ԫ��װ�ص�һ��AVX������
	//			//		__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��8��Ԫ��װ�ص�һ��AVX������
	//			//		vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // ��xiaoyuanhang�ж�Ӧλ��Ϊ0��Ԫ�ر�Ϊ1
	//			//		_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��xiaoyuanhang��8��Ԫ����
	//			//	}
	//			//}
	//		}
	//	}
	//	if (T == 1) {
	//		T = 0;
	//	}
	//	else {
	//		//t=0��ȫ0������Ԫ����
	//		t++;
	//	}
	//}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "�����˹��ԪSSE�洢���̲��л�����ʱ��Ϊ " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
	time2 += (tail3 - head3) * 1000.0 / freq3;

	/*int temp2 = 0;
	for (int i = 129; i >= 0; i--)
	{
		for (int j = 129; j >= 0; j--) {
			if (Result[i][j] == 1) {
				cout << j << " ";
				temp2 = 1;
			}
			if (j == 0 && temp2 == 1) {
				cout << endl;
				temp2 = 0;
			}
		}
	}*/

	ifs.close();
}
void SSE2() {
	ifstream ifs("C://Users//86183//Desktop//����Ԫ��.txt");//�ļ��Ķ���
	ifstream if1("C://Users//86183//Desktop//��Ԫ��.txt");
	ofstream out("C://Users//86183//Desktop//��Ԫ���.txt");

	int forline = 8;//����Ԫ��8��
	int line = 22;//��Ԫ��22��
	int artix = 130;//ÿһ����130��Ԫ��

	int xiaoyuanzi[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanzi[i][j] = 0;
		}
	}



	int xiaoyuanhang[8][130];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanhang[i][j] = 0;
		}
	}
	//��Ԫ�������

	int Result[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Result[i][j] = 0;
		}
	}

	string s;
	int temp1 = 0;
	for (int i = 1; i <= 22; i++) {
		getline(if1, s);
		stringstream ss(s);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//ÿһ�е�һ��Ԫ��Ϊ���б�ţ�ͬһ����Ӧλ��Ϊ1
		}
		temp1 = 0;
	}
	//��Ԫ�Ӷ���

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//��Ԫ�ӵĶ���


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//������Ԫ
	int T = 0;

	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //����1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) {//������Ԫ��
					for (int k = 0; k < 130; k++) {
						xiaoyuanzi[j][k] = xiaoyuanhang[t][k];
						Result[j][k] = xiaoyuanhang[t][k];
					}
					t++;
					//cout << "easeasd" << result[j][j] << " " << j << endl;
					//cout << t << endl;
					break;
				}
				else {
					for (int k = 0; k + 4 < 130; k += 4) { // 4��Ԫ��һ�����SSE��������
						__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // ��xiaoyuanzi��4��Ԫ��װ�ص�һ��SSE������
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��4��Ԫ��װ�ص�һ��SSE������
						vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // ��xiaoyuanhang�ж�Ӧλ��Ϊ0��Ԫ�ر�Ϊ1
						_mm_storeu_si128((__m128i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // ��SSE�����Ľ���洢��xiaoyuanhang��4��Ԫ����
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0��ȫ0������Ԫ����
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "�����˹��ԪSSE�洢���̲��л�����ʱ��Ϊ " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
	time3 += (tail3 - head3) * 1000.0 / freq3;

	/*int temp2 = 0;
	for (int i = 129; i >= 0; i--)
	{
		for (int j = 129; j >= 0; j--) {
			if (Result[i][j] == 1) {
				cout << j << " ";
				temp2 = 1;
			}
			if (j == 0 && temp2 == 1) {
				cout << endl;
				temp2 = 0;
			}
		}
	}*/

	ifs.close();
}
void SSE3() {
	ifstream ifs("C://Users//86183//Desktop//����Ԫ��.txt");//�ļ��Ķ���
	ifstream if1("C://Users//86183//Desktop//��Ԫ��.txt");
	ofstream out("C://Users//86183//Desktop//��Ԫ���.txt");

	int forline = 8;//����Ԫ��8��
	int line = 22;//��Ԫ��22��
	int artix = 130;//ÿһ����130��Ԫ��

	int xiaoyuanzi[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanzi[i][j] = 0;
		}
	}



	int xiaoyuanhang[8][130];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanhang[i][j] = 0;
		}
	}
	//��Ԫ�������



	int Result[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Result[i][j] = 0;
		}
	}

	string s;
	int temp1 = 0;
	for (int i = 1; i <= 22; i++) {
		getline(if1, s);
		stringstream ss(s);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//ÿһ�е�һ��Ԫ��Ϊ���б�ţ�ͬһ����Ӧλ��Ϊ1
		}
		temp1 = 0;
	}
	//��Ԫ�Ӷ���


	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//��Ԫ�ӵĶ���


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);





	int t = 0;//������Ԫ
	int T = 0;


	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //����1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //������Ԫ��
					for (int k = 0; k + 4 < 130; k += 4) { // 4��Ԫ��һ�����SSE��������
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��4��Ԫ��װ�ص�һ��SSE������
						_mm_storeu_si128((__m128i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // ��SSE�����Ľ���洢��xiaoyuanzi��4��Ԫ����
						_mm_storeu_si128((__m128i*) & Result[j][k], vec_xiaoyuanhang); // ��SSE�����Ľ���洢��Result��4��Ԫ����
					}
					t++;
					break;
				}
				else {
					for (int k = 0; k + 4 < 130; k += 4) { // 4��Ԫ��һ�����SSE��������
						__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // ��xiaoyuanzi��4��Ԫ��װ�ص�һ��SSE������
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��4��Ԫ��װ�ص�һ��SSE������
						vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // ��xiaoyuanhang�ж�Ӧλ��Ϊ0��Ԫ�ر�Ϊ1
						_mm_storeu_si128((__m128i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // ��SSE�����Ľ���洢��xiaoyuanhang��4��Ԫ����
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0��ȫ0������Ԫ����
			t++;
		}
	}








	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "�����˹��ԪSSE�洢���̲��л�����ʱ��Ϊ " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
	time4 += (tail3 - head3) * 1000.0 / freq3;

	/*int temp2 = 0;
	for (int i = 129; i >= 0; i--)
	{
		for (int j = 129; j >= 0; j--) {
			if (Result[i][j] == 1) {
				cout << j << " ";
				temp2 = 1;
			}
			if (j == 0 && temp2 == 1) {
				cout << endl;
				temp2 = 0;
			}
		}
	}*/

	ifs.close();
}
void AVX4() {
	ifstream ifs("C://Users//86183//Desktop//����Ԫ��.txt");//�ļ��Ķ���
	ifstream if1("C://Users//86183//Desktop//��Ԫ��.txt");
	ofstream out("C://Users//86183//Desktop//��Ԫ���.txt");

	int forline = 8;//����Ԫ��8��
	int line = 22;//��Ԫ��22��
	int artix = 130;//ÿһ����130��Ԫ��

	int xiaoyuanzi[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanzi[i][j] = 0;
		}
	}



	int xiaoyuanhang[8][130];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanhang[i][j] = 0;
		}
	}
	//��Ԫ�������

	int Result[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Result[i][j] = 0;
		}
	}

	string s;
	int temp1 = 0;
	for (int i = 1; i <= 22; i++) {
		getline(if1, s);
		stringstream ss(s);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//ÿһ�е�һ��Ԫ��Ϊ���б�ţ�ͬһ����Ӧλ��Ϊ1
		}
		temp1 = 0;
	}
	//��Ԫ�Ӷ���

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//��Ԫ�ӵĶ���


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//������Ԫ
	int T = 0;

	

	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //����1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //������Ԫ��
					for (int k = 0; k + 8 < 130; k += 8) { // 8��Ԫ��һ�����AVX��������
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��8��Ԫ��װ�ص�һ��AVX������
						_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��xiaoyuanzi��8��Ԫ����
						_mm256_storeu_si256((__m256i*) & Result[j][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��Result��8��Ԫ����
					}
					t++;
					break;
				}
				else {
					for (int k = 0; k < 130; k++) {
						if (xiaoyuanzi[j][k] == xiaoyuanhang[t][k]) {
							xiaoyuanhang[t][k] = 0;
						}
						else {
							xiaoyuanhang[t][k] = 1;
						}
					}
				}
				//else {
				//	for (int k = 0; k + 8 < 130; k += 8) { // 8��Ԫ��һ�����AVX��������
				//		__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // ��xiaoyuanzi��8��Ԫ��װ�ص�һ��AVX������
				//		__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��8��Ԫ��װ�ص�һ��AVX������
				//		vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // ��xiaoyuanhang�ж�Ӧλ��Ϊ0��Ԫ�ر�Ϊ1
				//		_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��xiaoyuanhang��8��Ԫ����
				//	}
				//}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0��ȫ0������Ԫ����
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "�����˹��ԪSSE�洢���̲��л�����ʱ��Ϊ " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
	time5 += (tail3 - head3) * 1000.0 / freq3;

	/*int temp2 = 0;
	for (int i = 129; i >= 0; i--)
	{
		for (int j = 129; j >= 0; j--) {
			if (Result[i][j] == 1) {
				cout << j << " ";
				temp2 = 1;
			}
			if (j == 0 && temp2 == 1) {
				cout << endl;
				temp2 = 0;
			}
		}
	}*/

	ifs.close();
}
void AVX5() {
	ifstream ifs("C://Users//86183//Desktop//����Ԫ��.txt");//�ļ��Ķ���
	ifstream if1("C://Users//86183//Desktop//��Ԫ��.txt");
	ofstream out("C://Users//86183//Desktop//��Ԫ���.txt");

	int forline = 8;//����Ԫ��8��
	int line = 22;//��Ԫ��22��
	int artix = 130;//ÿһ����130��Ԫ��

	int xiaoyuanzi[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanzi[i][j] = 0;
		}
	}



	int xiaoyuanhang[8][130];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanhang[i][j] = 0;
		}
	}
	//��Ԫ�������

	int Result[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Result[i][j] = 0;
		}
	}

	string s;
	int temp1 = 0;
	for (int i = 1; i <= 22; i++) {
		getline(if1, s);
		stringstream ss(s);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//ÿһ�е�һ��Ԫ��Ϊ���б�ţ�ͬһ����Ӧλ��Ϊ1
		}
		temp1 = 0;
	}
	//��Ԫ�Ӷ���

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//��Ԫ�ӵĶ���


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//������Ԫ
	int T = 0;



	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //����1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) {//������Ԫ��
					for (int k = 0; k < 130; k++) {
						xiaoyuanzi[j][k] = xiaoyuanhang[t][k];
						Result[j][k] = xiaoyuanhang[t][k];
					}
					t++;
					//cout << "easeasd" << result[j][j] << " " << j << endl;
					//cout << t << endl;
					break;
				}
				/*	else {
						for (int k = 0; k < 130; k++) {
							if (xiaoyuanzi[j][k] == xiaoyuanhang[t][k]) {
								xiaoyuanhang[t][k] = 0;
							}
							else {
								xiaoyuanhang[t][k] = 1;
							}
						}
					}*/
				else {
					for (int k = 0; k + 8 < 130; k += 8) { // 8��Ԫ��һ�����AVX��������
						__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // ��xiaoyuanzi��8��Ԫ��װ�ص�һ��AVX������
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��8��Ԫ��װ�ص�һ��AVX������
						vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // ��xiaoyuanhang�ж�Ӧλ��Ϊ0��Ԫ�ر�Ϊ1
						_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��xiaoyuanhang��8��Ԫ����
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0��ȫ0������Ԫ����
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "�����˹��ԪSSE�洢���̲��л�����ʱ��Ϊ " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
	time6 += (tail3 - head3) * 1000.0 / freq3;

	/*int temp2 = 0;
	for (int i = 129; i >= 0; i--)
	{
		for (int j = 129; j >= 0; j--) {
			if (Result[i][j] == 1) {
				cout << j << " ";
				temp2 = 1;
			}
			if (j == 0 && temp2 == 1) {
				cout << endl;
				temp2 = 0;
			}
		}
	}*/

	ifs.close();
}
void AVX6() {
	ifstream ifs("C://Users//86183//Desktop//����Ԫ��.txt");//�ļ��Ķ���
	ifstream if1("C://Users//86183//Desktop//��Ԫ��.txt");
	ofstream out("C://Users//86183//Desktop//��Ԫ���.txt");

	int forline = 8;//����Ԫ��8��
	int line = 22;//��Ԫ��22��
	int artix = 130;//ÿһ����130��Ԫ��

	int xiaoyuanzi[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanzi[i][j] = 0;
		}
	}



	int xiaoyuanhang[8][130];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 130; j++) {
			xiaoyuanhang[i][j] = 0;
		}
	}
	//��Ԫ�������

	int Result[130][130];
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			Result[i][j] = 0;
		}
	}

	string s;
	int temp1 = 0;
	for (int i = 1; i <= 22; i++) {
		getline(if1, s);
		stringstream ss(s);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//ÿһ�е�һ��Ԫ��Ϊ���б�ţ�ͬһ����Ӧλ��Ϊ1
		}
		temp1 = 0;
	}
	//��Ԫ�Ӷ���

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//��ʼ��Ԫ
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//��Ԫ�ӵĶ���


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//������Ԫ
	int T = 0;



	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //����1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //������Ԫ��
					for (int k = 0; k + 8 < 130; k += 8) { // 8��Ԫ��һ�����AVX��������
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��8��Ԫ��װ�ص�һ��AVX������
						_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��xiaoyuanzi��8��Ԫ����
						_mm256_storeu_si256((__m256i*) & Result[j][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��Result��8��Ԫ����
					}
					t++;
					break;
				}
				/*	else {
						for (int k = 0; k < 130; k++) {
							if (xiaoyuanzi[j][k] == xiaoyuanhang[t][k]) {
								xiaoyuanhang[t][k] = 0;
							}
							else {
								xiaoyuanhang[t][k] = 1;
							}
						}
					}*/
				else {
					for (int k = 0; k + 8 < 130; k += 8) { // 8��Ԫ��һ�����AVX��������
						__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // ��xiaoyuanzi��8��Ԫ��װ�ص�һ��AVX������
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // ��xiaoyuanhang��8��Ԫ��װ�ص�һ��AVX������
						vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // ��xiaoyuanhang�ж�Ӧλ��Ϊ0��Ԫ�ر�Ϊ1
						_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // ��AVX�����Ľ���洢��xiaoyuanhang��8��Ԫ����
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0��ȫ0������Ԫ����
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "�����˹��ԪSSE�洢���̲��л�����ʱ��Ϊ " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
	time7+= (tail3 - head3) * 1000.0 / freq3;

	/*int temp2 = 0;
	for (int i = 129; i >= 0; i--)
	{
		for (int j = 129; j >= 0; j--) {
			if (Result[i][j] == 1) {
				cout << j << " ";
				temp2 = 1;
			}
			if (j == 0 && temp2 == 1) {
				cout << endl;
				temp2 = 0;
			}
		}
	}*/

	ifs.close();
}
int main() {
	for (int i = 1; i <= 20; i++)
	{
		chuanx();
		SSE1();
		SSE2();
		SSE3();
		AVX4();
		AVX5();
		AVX6();
	}
	cout << "�����㷨ƽ������ʱ��" << time1 / 20 <<"ms"<< endl;
	cout << "�洢����������ƽ������ʱ��" << time2 / 20 << "ms" << endl;
	cout << "������������ƽ������ʱ��" << time3 / 20 << "ms" << endl;
	cout << "SSE������ƽ������ʱ��" << time4 / 20 << "ms" << endl;
	cout << "AVX1������ƽ������ʱ��" << time5 / 20 << "ms" << endl;
	cout << "AVX2������ƽ������ʱ��" << time6 / 20 << "ms" << endl;
	cout << "AVX3������ƽ������ʱ��" << time7 / 20 << "ms" << endl;
}