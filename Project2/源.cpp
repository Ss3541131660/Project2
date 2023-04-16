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
	ifstream ifs("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream if1("C://Users//86183//Desktop//消元子.txt");
	ofstream out("C://Users//86183//Desktop//消元结果.txt");

	int forline = 8;//被消元行8行
	int line = 22;//消元子22行
	int artix = 130;//每一行有130个元素

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
	//消元结果矩阵



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
			//开始消元
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//每一行第一个元素为该行编号，同一行相应位置为1
		}
		temp1 = 0;
	}
	//消元子读入


	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//开始消元
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//消元子的读入


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//正在消元
	int T = 0;
	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j>=0; j--) {
			if (xiaoyuanhang[t][j] == 1) {//等于1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) {//升级消元子
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
			//t=0，全0，被消元完了
			t++;
		}
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	time1 += (tail3 - head3) * 1000.0 / freq3;
	/*cout << "高斯消元串行算法并行化运行时间为 " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;


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
	ifstream ifs("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream if1("C://Users//86183//Desktop//消元子.txt");
	ofstream out("C://Users//86183//Desktop//消元结果.txt");

	int forline = 8;//被消元行8行
	int line = 22;//消元子22行
	int artix = 130;//每一行有130个元素

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
	//消元结果矩阵



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
			//开始消元
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//每一行第一个元素为该行编号，同一行相应位置为1
		}
		temp1 = 0;
	}
	//消元子读入


	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//开始消元
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//消元子的读入

	
	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	//int t = 0;//正在消元
	//int T = 0;
	//while (true) {
	//	if (t == 8) {
	//		break;
	//	}
	//	for (int j = 129; j>=0; j--) {
	//		if (xiaoyuanhang[t][j] == 1) {//等于1
	//			T = 1;
	//			if (xiaoyuanzi[j][j] == 0) {//升级消元子
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
	//		//t=0，全0，被消元完了
	//		t++;
	//	}
	//}
	// 
	// 
	// 
	// end time




	int t = 0;//正在消元
	int T = 0;

	//__m128i ones = _mm_set1_epi32(1); // 初始化一个全为1的向量

	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //等于1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //升级消元子
					for (int k = 0; k+4 < 130; k += 4) { // 4个元素一组进行SSE向量运算
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的4个元素装载到一个SSE向量中
						_mm_storeu_si128((__m128i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到xiaoyuanzi的4个元素中
						_mm_storeu_si128((__m128i*) & Result[j][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到Result的4个元素中
					}
					t++;
					break;
				}
				//else {
				//	for (int k = 0; k + 4 < 130; k += 4) { // 4个元素一组进行SSE向量运算
				//		__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的4个元素装载到一个SSE向量中
				//		__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的4个元素装载到一个SSE向量中
				//		vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将xiaoyuanhang中对应位置为0的元素变为1
				//		_mm_storeu_si128((__m128i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到xiaoyuanhang的4个元素中
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
			//t=0，全0，被消元完了
			t++;
		}
	}





	//__m256i ones = _mm256_set1_epi32(1); // 初始化一个全为1的向量

	//while (true) {
	//	if (t == 8) {
	//		break;
	//	}
	//	for (int j = 129; j >= 0; j--) {
	//		if (xiaoyuanhang[t][j] == 1) { //等于1
	//			T = 1;
	//			if (xiaoyuanzi[j][j] == 0) { //升级消元子
	//				for (int k = 0; k + 8 < 130; k += 8) { // 8个元素一组进行AVX向量运算
	//					__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的8个元素装载到一个AVX向量中
	//					_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanzi的8个元素中
	//					_mm256_storeu_si256((__m256i*) & Result[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到Result的8个元素中
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
	//			//	for (int k = 0; k + 8 < 130; k += 8) { // 8个元素一组进行AVX向量运算
	//			//		__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的8个元素装载到一个AVX向量中
	//			//		__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的8个元素装载到一个AVX向量中
	//			//		vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将xiaoyuanhang中对应位置为0的元素变为1
	//			//		_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanhang的8个元素中
	//			//	}
	//			//}
	//		}
	//	}
	//	if (T == 1) {
	//		T = 0;
	//	}
	//	else {
	//		//t=0，全0，被消元完了
	//		t++;
	//	}
	//}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "特殊高斯消元SSE存储过程并行化运行时间为 " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
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
	ifstream ifs("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream if1("C://Users//86183//Desktop//消元子.txt");
	ofstream out("C://Users//86183//Desktop//消元结果.txt");

	int forline = 8;//被消元行8行
	int line = 22;//消元子22行
	int artix = 130;//每一行有130个元素

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
	//消元结果矩阵

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
			//开始消元
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//每一行第一个元素为该行编号，同一行相应位置为1
		}
		temp1 = 0;
	}
	//消元子读入

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//开始消元
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//消元子的读入


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//正在消元
	int T = 0;

	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //等于1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) {//升级消元子
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
					for (int k = 0; k + 4 < 130; k += 4) { // 4个元素一组进行SSE向量运算
						__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的4个元素装载到一个SSE向量中
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的4个元素装载到一个SSE向量中
						vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将xiaoyuanhang中对应位置为0的元素变为1
						_mm_storeu_si128((__m128i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到xiaoyuanhang的4个元素中
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0，全0，被消元完了
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "特殊高斯消元SSE存储过程并行化运行时间为 " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
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
	ifstream ifs("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream if1("C://Users//86183//Desktop//消元子.txt");
	ofstream out("C://Users//86183//Desktop//消元结果.txt");

	int forline = 8;//被消元行8行
	int line = 22;//消元子22行
	int artix = 130;//每一行有130个元素

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
	//消元结果矩阵



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
			//开始消元
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//每一行第一个元素为该行编号，同一行相应位置为1
		}
		temp1 = 0;
	}
	//消元子读入


	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//开始消元
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//消元子的读入


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);





	int t = 0;//正在消元
	int T = 0;


	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //等于1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //升级消元子
					for (int k = 0; k + 4 < 130; k += 4) { // 4个元素一组进行SSE向量运算
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的4个元素装载到一个SSE向量中
						_mm_storeu_si128((__m128i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到xiaoyuanzi的4个元素中
						_mm_storeu_si128((__m128i*) & Result[j][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到Result的4个元素中
					}
					t++;
					break;
				}
				else {
					for (int k = 0; k + 4 < 130; k += 4) { // 4个元素一组进行SSE向量运算
						__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的4个元素装载到一个SSE向量中
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的4个元素装载到一个SSE向量中
						vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将xiaoyuanhang中对应位置为0的元素变为1
						_mm_storeu_si128((__m128i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到xiaoyuanhang的4个元素中
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0，全0，被消元完了
			t++;
		}
	}








	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "特殊高斯消元SSE存储过程并行化运行时间为 " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
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
	ifstream ifs("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream if1("C://Users//86183//Desktop//消元子.txt");
	ofstream out("C://Users//86183//Desktop//消元结果.txt");

	int forline = 8;//被消元行8行
	int line = 22;//消元子22行
	int artix = 130;//每一行有130个元素

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
	//消元结果矩阵

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
			//开始消元
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//每一行第一个元素为该行编号，同一行相应位置为1
		}
		temp1 = 0;
	}
	//消元子读入

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//开始消元
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//消元子的读入


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//正在消元
	int T = 0;

	

	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //等于1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //升级消元子
					for (int k = 0; k + 8 < 130; k += 8) { // 8个元素一组进行AVX向量运算
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的8个元素装载到一个AVX向量中
						_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanzi的8个元素中
						_mm256_storeu_si256((__m256i*) & Result[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到Result的8个元素中
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
				//	for (int k = 0; k + 8 < 130; k += 8) { // 8个元素一组进行AVX向量运算
				//		__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的8个元素装载到一个AVX向量中
				//		__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的8个元素装载到一个AVX向量中
				//		vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将xiaoyuanhang中对应位置为0的元素变为1
				//		_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanhang的8个元素中
				//	}
				//}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0，全0，被消元完了
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "特殊高斯消元SSE存储过程并行化运行时间为 " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
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
	ifstream ifs("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream if1("C://Users//86183//Desktop//消元子.txt");
	ofstream out("C://Users//86183//Desktop//消元结果.txt");

	int forline = 8;//被消元行8行
	int line = 22;//消元子22行
	int artix = 130;//每一行有130个元素

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
	//消元结果矩阵

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
			//开始消元
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//每一行第一个元素为该行编号，同一行相应位置为1
		}
		temp1 = 0;
	}
	//消元子读入

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//开始消元
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//消元子的读入


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//正在消元
	int T = 0;



	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //等于1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) {//升级消元子
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
					for (int k = 0; k + 8 < 130; k += 8) { // 8个元素一组进行AVX向量运算
						__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的8个元素装载到一个AVX向量中
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的8个元素装载到一个AVX向量中
						vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将xiaoyuanhang中对应位置为0的元素变为1
						_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanhang的8个元素中
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0，全0，被消元完了
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "特殊高斯消元SSE存储过程并行化运行时间为 " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
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
	ifstream ifs("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream if1("C://Users//86183//Desktop//消元子.txt");
	ofstream out("C://Users//86183//Desktop//消元结果.txt");

	int forline = 8;//被消元行8行
	int line = 22;//消元子22行
	int artix = 130;//每一行有130个元素

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
	//消元结果矩阵

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
			//开始消元
			if (temp1 == 0) {
				temp1 = num;
			}
			xiaoyuanzi[temp1][num] = 1;//每一行第一个元素为该行编号，同一行相应位置为1
		}
		temp1 = 0;
	}
	//消元子读入

	string s1;
	for (int i = 1; i <= 8; i++) {
		getline(ifs, s1);
		stringstream ss(s1);
		int num;
		while (ss >> num) {
			//开始消元
			xiaoyuanhang[i - 1][num] = 1;
		}
	}
	//消元子的读入


	long long head3, tail3, freq3; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq3);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head3);

	int t = 0;//正在消元
	int T = 0;



	while (true) {
		if (t == 8) {
			break;
		}
		for (int j = 129; j >= 0; j--) {
			if (xiaoyuanhang[t][j] == 1) { //等于1
				T = 1;
				if (xiaoyuanzi[j][j] == 0) { //升级消元子
					for (int k = 0; k + 8 < 130; k += 8) { // 8个元素一组进行AVX向量运算
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的8个元素装载到一个AVX向量中
						_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanzi的8个元素中
						_mm256_storeu_si256((__m256i*) & Result[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到Result的8个元素中
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
					for (int k = 0; k + 8 < 130; k += 8) { // 8个元素一组进行AVX向量运算
						__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的8个元素装载到一个AVX向量中
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & xiaoyuanhang[t][k]); // 将xiaoyuanhang的8个元素装载到一个AVX向量中
						vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将xiaoyuanhang中对应位置为0的元素变为1
						_mm256_storeu_si256((__m256i*) & xiaoyuanhang[t][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanhang的8个元素中
					}
				}
			}
		}
		if (T == 1) {
			T = 0;
		}
		else {
			//t=0，全0，被消元完了
			t++;
		}
	}


	QueryPerformanceCounter((LARGE_INTEGER*)&tail3);
	//cout << "特殊高斯消元SSE存储过程并行化运行时间为 " << (tail3 - head3) * 1000.0 / freq3 << "ms" << endl;
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
	cout << "串行算法平均运行时间" << time1 / 20 <<"ms"<< endl;
	cout << "存储过程向量化平均运行时间" << time2 / 20 << "ms" << endl;
	cout << "异或过程向量化平均运行时间" << time3 / 20 << "ms" << endl;
	cout << "SSE向量化平均运行时间" << time4 / 20 << "ms" << endl;
	cout << "AVX1向量化平均运行时间" << time5 / 20 << "ms" << endl;
	cout << "AVX2向量化平均运行时间" << time6 / 20 << "ms" << endl;
	cout << "AVX3向量化平均运行时间" << time7 / 20 << "ms" << endl;
}