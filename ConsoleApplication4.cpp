// ConsoleApplication4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include <ctime>
using namespace std;
int answer[4];
bool isDuplicate(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;  // 중복되는 숫자가 있으면 true 반환
        }
    }
    return false;  // 중복이 없으면 false 반환
}

void numberBaseball()
{
    bool fourstrike = false;
    int strikecount, ballcount;
    srand(time(0));

    // 정답 배열 초기화
    for (int i = 0; i < 4; i++)
    {
        int newNum;
        do
        {
            newNum = rand() % 9 + 1;  // 1부터 9까지의 난수 생성
        } while (isDuplicate(answer, i, newNum));  // 중복이면 다시 생성
        answer[i] = newNum;
    }

    while (!fourstrike)
    {
        int arr[4];  // 사용자가 입력할 배열
        strikecount = 0;
        ballcount = 0;

        // 사용자로부터 4개의 숫자를 입력받음
        cout << "4개의 숫자를 입력하세요 (1~9): ";
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }

        // 스트라이크 계산
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] == answer[i])
            {
                strikecount++;
            }
        }

        // 스트라이크가 4개이면 승리
        if (strikecount == 4)
        {
            fourstrike = true;
            cout << "4스트라이크! 정답입니다!" << endl;
        }
        else
        {
            // 볼 계산
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (arr[i] == answer[j] && i != j)  // 다른 위치에 있지만 같은 숫자가 있으면 볼
                    {
                        ballcount++;
                    }
                }
            }
            // 결과 출력
            cout << strikecount << " 스트라이크, " << ballcount << " 볼" << endl;
        }
    }
}
int main()
{


    numberBaseball();

}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
