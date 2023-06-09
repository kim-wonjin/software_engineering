// 헤더 선언
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "DataBase.h"
#include "File.h"

#include "SignUp.h"
#include "SignUpUI.h"
#include "Login.h"
#include "LoginUI.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join(DataBase* dataBase, File* file);
void login(DataBase* dataBase, File* file);
void searchRecruitment(DataBase* dataBase, File* file);
void program_exit(File* file);


int main() {

	doTask();
	return 0;
}


void doTask() {

	File* file = new File();
	DataBase* dataBase = new DataBase();

	// 메뉴 파싱을 위한 level 구분을 위한 변수 
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;


	while (!is_program_exit) {
		// 입력파일에서 메뉴 숫자 2개를 읽기
		file->ifs >> menu_level_1 >> menu_level_2;
		file->readed = file->ifs.tellg();

		// 메뉴 구분 및 해당 연산 수행 
		switch (menu_level_1)
		{
		case 1: {
			switch (menu_level_2) {
			case 1: // "1.1. 회원가입“ 메뉴 부분 
			{
				join(dataBase, file);
				break;
			}
			case 2: // "1.2. 회원탈퇴" 메뉴 부분 
			{
				break;
			}
			default:
				break;
			}	
		}break;
			  
		case 2: {
			switch (menu_level_2) {
			case 1: // "2.1. 로그인“ 메뉴 부분
			{
				login(dataBase, file);
				break;
			}
			case 2: // "2.2. 로그아웃" 메뉴 부분 
			{
				break;
			}
			default:
				break;
			}
		}break;

		case 3: {
			switch (menu_level_2) {
			case 1: // "3.1. 채용 정보 등록“ 메뉴 부분 
			{
				break;
			}
			case 2: // "3.2. 등록된 채용 정보 조회" 메뉴 부분 
			{
				break;
			}
			default:
				break;
			}
		}break;

		case 4: {
			switch (menu_level_2) {
			case 1: // "4.1. 채용 정보 검색“ 메뉴 부분 
			{
				searchRecruitment(dataBase, file);
				break;
			}
			case 2: // "4.2. 채용 지원" 메뉴 부분 
			{
				break;
			}
			case 3: // "4.3. 지원 정보 조회" 메뉴 부분 
			{
				break;
			}
			case 4: // "4.4. 지원 취소" 메뉴 부분 
			{
				break;
			}
			default:
				break;
			}
		}break;

		case 5: {
			switch (menu_level_2) {
			case 1: // "5.1. 지원 정보 통계“ 메뉴 부분 
			{
				break;
			}
			default:
				break;
			}
		}break;

		case 6: {
			switch (menu_level_2) {
			case 1: // "6.1. 종료“ 메뉴 부분
			{
				program_exit(file);
				is_program_exit = 1;
				break;
			}
			default:
				break;
			}
		}break;

		default: {
			break;
		}
		}
	}
	return;
}


// "1.1. 회원가입“ 메뉴 부분
void join(DataBase* dataBase, File* file) {

	SignUp* signUp = new SignUp(dataBase);
	signUp->getSignUpUI()->addNewMember(signUp, file);
}


// "2.1. 로그인“ 메뉴 부분 
void login(DataBase* dataBase, File* file) {
	Login* login = new Login(dataBase);
	login->getLoginUI()->login(login, file);
}


// "4.1. 채용 정보 검색“ 메뉴 부분
void searchRecruitment(DataBase* dataBase, File* file) {
}


// "6.1. 종료“ 메뉴 부분
void program_exit(File* file) {
	cout << "6.1 종료";
	file->ofs << "6.1 종료";
	file->ifs.close();
	file->ofs.close();
}
