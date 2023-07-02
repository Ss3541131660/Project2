#include<iostream>
#include<fstream>
#include<ctime>
#include<Windows.h>
#include<string>
#include<sstream>
#include <immintrin.h>
#include <emmintrin.h>
#include <intrin.h>
using namespace std;
#define juzhen 23045//矩阵规模
#define xzi 18748//消元子行数
#define bxhang 14325//被消元行
int xiaoyuanzi[juzhen][juzhen];//消元子矩阵(0-129)
int beixiaoyuanhang[bxhang][juzhen];//被消元行矩阵
int Result[bxhang][juzhen];//消元结果矩阵
//矩阵初始化和文件内容输入
//void check() {
//	int xiaoyuanzitemp = 0;
//	for (int i = juzhen - 1; i >= 0; i--) {
//		for (int j = juzhen - 1; j >= 0; j--) {
//			if (xiaoyuanzi[i][j] == 1) {
//				xiaoyuanzitemp = 1;
//				out << j << " ";
//			}
//			if (j == 0 && xiaoyuanzitemp == 1) {
//				out << endl;
//			}
//		}
//		xiaoyuanzitemp = 0;
//	}
//
//	for (int i = juzhen - 1; i >= 0; i--) {
//		for (int j = juzhen - 1; j >= 0; j--) {
//			if (xiaoyuanzi[i][j] == 1) {
//				xiaoyuanzitemp = 1;
//				cout << j << " ";
//			}
//			if (j == 0 && xiaoyuanzitemp == 1) {
//				cout << endl;
//			}
//		}
//		xiaoyuanzitemp = 0;
//	}
//}
//验证消元子是否正确
//矩阵初始化和文件读入
void xiaoyuan() {
	ifstream if1("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream ifs("C://Users//86183//Desktop//消元子.txt");//文件读入
	ofstream out("C://Users//86183//Desktop//消元结果.txt");//文件写出

	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容

	long long head, tail, freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	//开始测试

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				//j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) {//可以消元
					for (int k = juzhen - 1; k >= 0; k--) {
						//异或消元
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else {//升级消元子
					for (int k = juzhen - 1; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	//停止测试
	cout << "time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
	// 输出结果
}
//串行消元
void gauss_part1_SIMD() {
	ifstream if1("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream ifs("C://Users//86183//Desktop//消元子.txt");//文件读入
	ofstream out("C://Users//86183//Desktop//消元结果.txt");//文件写出

	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容

	long long head, tail, freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	//开始测试

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				//j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) {//可以消元
					for (int k = juzhen - 1; k >= 0; k--) {
						//异或消元
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else {//升级消元子
					int k = juzhen - 1;
					for (; k - 4 >= 0; k -= 4) {
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & beixiaoyuanhang[i][k]);
						//将beoxiaoyuanhang的4个元素装载到一个SSE向量中
						_mm_storeu_si128((__m128i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang);
						//将SSE向量的结果存储到xiaoyuanzi的4个元素中
						_mm_storeu_si128((__m128i*) & Result[T1 - 1][k], vec_xiaoyuanhang);
						//将SSE向量的结果存储到Result的4个元素中
					}
					for (; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	//停止测试
	cout << "SSE_part1_time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
	// 输出结果

}
//升级消元子部分SIMD并行
void gauss_part2_SIMD() {
	ifstream if1("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream ifs("C://Users//86183//Desktop//消元子.txt");//文件读入
	ofstream out("C://Users//86183//Desktop//消元结果.txt");//文件写出

	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容

	long long head, tail, freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	//开始测试

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				//j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) {//可以消元
					int k = juzhen - 1;
					for (; k - 4 >= 0; k -= 4) { // 4个元素一组进行SSE向量运算
						__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的4个元素装载到一个SSE向量中
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & beixiaoyuanhang[i][k]); // 将beixiaoyuanhang的4个元素装载到一个SSE向量中
						vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将beixiaoyuanhang中对应位置为0的元素变为1
						_mm_storeu_si128((__m128i*) & beixiaoyuanhang[i][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到beixiaoyuanhang的4个元素中
					}
					for (; k >= 0; k--) {
						//异或消元
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else {//升级消元子
					for (int k = juzhen - 1; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	//停止测试
	cout << "SSE_part2_time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
	// 输出结果
}
//异或部分SIMD并行
void gauss_part3_SIMD() {
	ifstream if1("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream ifs("C://Users//86183//Desktop//消元子.txt");//文件读入
	ofstream out("C://Users//86183//Desktop//消元结果.txt");//文件写出

	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容

	long long head, tail, freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	//开始测试

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				//j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) {//可以消元
					int k = juzhen - 1;
					for (; k - 4 >= 0; k -= 4) { // 4个元素一组进行SSE向量运算
						__m128i vec_xiaoyuanzi = _mm_loadu_si128((__m128i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的4个元素装载到一个SSE向量中
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & beixiaoyuanhang[i][k]); // 将beixiaoyuanhang的4个元素装载到一个SSE向量中
						vec_xiaoyuanhang = _mm_xor_si128(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将beixiaoyuanhang中对应位置为0的元素变为1
						_mm_storeu_si128((__m128i*) & beixiaoyuanhang[i][k], vec_xiaoyuanhang); // 将SSE向量的结果存储到beixiaoyuanhang的4个元素中
					}
					for (; k >= 0; k--) {
						//异或消元
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else {//升级消元子
					int k = juzhen - 1;
					for (; k - 4 >= 0; k -= 4) {
						__m128i vec_xiaoyuanhang = _mm_loadu_si128((__m128i*) & beixiaoyuanhang[i][k]);
						//将beixiaoyuanhang的4个元素装载到一个SSE向量中
						_mm_storeu_si128((__m128i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang);
						//将SSE向量的结果存储到xiaoyuanzi的4个元素中
						_mm_storeu_si128((__m128i*) & Result[T1 - 1][k], vec_xiaoyuanhang);
						//将SSE向量的结果存储到Result的4个元素中
					}
					for (; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	//停止测试
	cout << "SSE_part3_time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
	// 输出结果
}
//完全SIMD并行
void gauss_part1_AVX() {
	ifstream if1("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream ifs("C://Users//86183//Desktop//消元子.txt");//文件读入
	ofstream out("C://Users//86183//Desktop//消元结果.txt");//文件写出

	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容

	long long head, tail, freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	//开始测试

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				//j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) {//可以消元
					for (int k = juzhen - 1; k >= 0; k--) {
						//异或消元
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else {//升级消元子
					int k = juzhen - 1;
					for (; k - 8 >= 0; k -= 8) {
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & beixiaoyuanhang[i][k]); // 将beixiaoyuanhang的8个元素装载到一个AVX向量中
						_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanzi的8个元素中
						_mm256_storeu_si256((__m256i*) & Result[T1 - 1][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到Result的8个元素中
					}
					for (; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	//停止测试
	cout << "SSE_part1_time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
	// 输出结果
}
//升级消元子部分AVX并行
void gauss_part2_AVX() {
	ifstream if1("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream ifs("C://Users//86183//Desktop//消元子.txt");//文件读入
	ofstream out("C://Users//86183//Desktop//消元结果.txt");//文件写出

	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容

	long long head, tail, freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	//开始测试

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				//j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) {//可以消元
					int k = juzhen - 1;
					for (; k - 8 >= 0; k -= 8) { // 8个元素一组进行AVX向量运算
						__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的8个元素装载到一个AVX向量中
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & beixiaoyuanhang[i][k]); // 将beixiaoyuanhang的8个元素装载到一个AVX向量中
						vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将beixiaoyuanhang中对应位置为0的元素变为1
						_mm256_storeu_si256((__m256i*) & beixiaoyuanhang[i][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到beixiaoyuanhang的8个元素中
					}
					for (; k >= 0; k--) {
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else {//升级消元子
					for (int k = juzhen - 1; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	//停止测试
	cout << "SSE_part2_time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
	// 输出结果
}
//异或部分AVX并行
void gauss_part3_AVX() {
	ifstream if1("C://Users//86183//Desktop//被消元行.txt");//文件的读入
	ifstream ifs("C://Users//86183//Desktop//消元子.txt");//文件读入
	ofstream out("C://Users//86183//Desktop//消元结果.txt");//文件写出

	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容

	long long head, tail, freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	//开始测试

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				//j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) {//可以消元
					int k = juzhen - 1;
					for (; k - 8 >= 0; k -= 8) { // 8个元素一组进行AVX向量运算
						__m256i vec_xiaoyuanzi = _mm256_loadu_si256((__m256i*) & xiaoyuanzi[j][k]); // 将xiaoyuanzi的8个元素装载到一个AVX向量中
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & beixiaoyuanhang[i][k]); // 将beixiaoyuanhang的8个元素装载到一个AVX向量中
						vec_xiaoyuanhang = _mm256_xor_si256(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将beixiaoyuanhang中对应位置为0的元素变为1
						_mm256_storeu_si256((__m256i*) & beixiaoyuanhang[i][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到beixiaoyuanhang的8个元素中
					}
					for (; k >= 0; k--) {
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else {//升级消元子
					int k = juzhen - 1;
					for (; k - 8 >= 0; k -= 8) {
						__m256i vec_xiaoyuanhang = _mm256_loadu_si256((__m256i*) & beixiaoyuanhang[i][k]); // 将beixiaoyuanhang的8个元素装载到一个AVX向量中
						_mm256_storeu_si256((__m256i*) & xiaoyuanzi[j][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到xiaoyuanzi的8个元素中
						_mm256_storeu_si256((__m256i*) & Result[T1 - 1][k], vec_xiaoyuanhang); // 将AVX向量的结果存储到Result的8个元素中
					}
					for (; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}

	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	//停止测试
	cout << "SSE_part3_time:" << (tail - head) * 1000.0 / freq << "ms" << endl;
	// 输出结果
}
//完全AVX并行
//
//void getout() {
//	int outtemp = 0;
//	for (int i = bxhang - 1; i >= 0; i--) {
//		for (int j = juzhen - 1; j >= 0; j--) {
//			if (Result[i][j] == 1) {
//				outtemp = 1;
//				out << j << " ";
//			}
//			if (j == 0 && outtemp == 1) {
//				out << endl;
//			}
//		}
//		outtemp = 0;
//	}
//	/*for (int i = bxhang - 1; i >= 0; i--) {
//		for (int j = juzhen - 1; j >= 0; j--) {
//			if (Result[i][j] == 1) {
//				outtemp = 1;
//				cout << j << " ";
//			}
//			if (j == 0 && outtemp == 1) {
//				cout << endl;
//			}
//		}
//		outtemp = 0;
//	}*/
//}
//输出结果

void neon() {
	int T1 = bxhang;
	//矩阵初始化
	for (int i = 0; i < juzhen; i++) {
		for (int j = 0; j < juzhen; j++) {
			xiaoyuanzi[juzhen][juzhen] = 0;
		}
	}
	//消元子矩阵初始化
	for (int i = 0; i < bxhang; i++) {
		for (int j = 0; j < bxhang; j++) {
			Result[i][j] = 0;
			beixiaoyuanhang[i][j] = 0;
		}
	}
	//结果矩阵和被消元行矩阵初始化



	///读入消元子文件内容
	string s1;
	int temp1 = xzi;
	int T = 0;
	while (temp1 != 0) {
		getline(ifs, s1);
		stringstream ss(s1);//一次读入一行
		int num;
		while (ss >> num) {
			if (T == 0) {
				T = num;
				//此时T为首项
			}
			xiaoyuanzi[T][num] = 1;
		}
		T = 0;
		temp1--;//每读完一行-1
	}

	string s2;
	int temp2 = bxhang;
	while (temp2 != 0) {
		getline(if1, s2);
		stringstream ss(s2);
		int num;
		while (ss >> num) {
			beixiaoyuanhang[temp2 - 1][num] = 1;
		}
		//T = 0;
		temp2--;
	}

	//读入被消元行文件内容
	struct timespec sts, ets;
	timespec_get(&sts, TIME_UTC);

	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (beixiaoyuanhang[i][j] == 1) {
				// j对应的位置需要消元
				if (xiaoyuanzi[j][j] == 1) { // 可以消元
					int k = juzhen - 1;
					for (; k - 4 >= 0; k -= 4) { // 4个元素一组进行Neon向量运算
						int32x4_t vec_xiaoyuanzi = vld1q_s32(reinterpret_cast<const int32_t*>(&xiaoyuanzi[j][k])); // 将xiaoyuanzi的4个元素装载到一个Neon向量中
						int32x4_t vec_xiaoyuanhang = vld1q_s32(reinterpret_cast<const int32_t*>(&beixiaoyuanhang[i][k])); // 将beixiaoyuanhang的4个元素装载到一个Neon向量中
						vec_xiaoyuanhang = veorq_s32(vec_xiaoyuanhang, vec_xiaoyuanzi); // 将beixiaoyuanhang中对应位置为0的元素变为1
						vst1q_s32(reinterpret_cast<int32_t*>(&beixiaoyuanhang[i][k]), vec_xiaoyuanhang); // 将Neon向量的结果存储到beixiaoyuanhang的4个元素中
					}
					for (; k >= 0; k--) {
						if (xiaoyuanzi[j][k] == beixiaoyuanhang[i][k]) {
							beixiaoyuanhang[i][k] = 0;
						}
						else {
							beixiaoyuanhang[i][k] = 1;
						}
					}
				}
				else { // 升级消元子
					int k = juzhen - 1;
					for (; k - 4 >= 0; k -= 4) {
						int32x4_t vec_xiaoyuanhang = vld1q_s32(reinterpret_cast<const int32_t*>(&beixiaoyuanhang[i][k])); // 将beixiaoyuanhang的4个元素装载到一个Neon向量中
						vst1q_s32(reinterpret_cast<int32_t*>(&xiaoyuanzi[j][k]), vec_xiaoyuanhang); // 将Neon向量的结果存储到xiaoyuanzi的4个元素中
						vst1q_s32(reinterpret_cast<int32_t*>(&Result[T1 - 1][k]), vec_xiaoyuanhang); // 将Neon向量的结果存储到Result的4个元素中
					}
					for (; k >= 0; k--) {
						xiaoyuanzi[j][k] = beixiaoyuanhang[i][k];
						Result[T1 - 1][k] = beixiaoyuanhang[i][k];
					}
					T1--;
					break;
				}
			}
		}
	}

	timespec_get(&ets, TIME_UTC);
	time_t dsec = ets.tv_sec - sts.tv_sec;
	long dnsec = ets.tv_nsec - sts.tv_nsec;
	if (dnsec < 0) {
		dsec--;
		dnsec += 1000000000ll;
	}
	printf("%lld.%09llds\n", dsec, dnsec);
}
//串行消元
void getout() {
	int outtemp = 0;
	for (int i = bxhang - 1; i >= 0; i--) {
		for (int j = juzhen - 1; j >= 0; j--) {
			if (Result[i][j] == 1) {
				outtemp = 1;
				out << j << " ";
			}
			if (j == 0 && outtemp == 1) {
				out << endl;
			}
		}
	}
}
int main() {

	//check();//验证结果是否正确的函数
	//xiaoyuan();
	xiaoyuan();
	gauss_part1_SIMD();
	gauss_part2_SIMD();
	gauss_part3_SIMD();
	gauss_part1_AVX();
	gauss_part2_AVX();
	gauss_part3_AVX();
	//getout();			//为了防止不同算法同时写文件导致文件有多个结果，所以只有一次写文件操作
}
