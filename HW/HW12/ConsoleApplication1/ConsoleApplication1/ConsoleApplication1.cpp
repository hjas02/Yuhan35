#include <iostream>
#include <chrono>
#include <thread>

int main() {
    int count = 0;
    const int time = 1000; // 1초 = 1000 밀리초

    while (count < 100) {
        auto start = std::chrono::steady_clock::now();

        count++;
        std::cout << "카운트: " << count;

        auto end = std::chrono::steady_clock::now();        // 루프 종료 시간
        std::chrono::duration<double, std::milli> elapsed = end - start; // 루프 실행 시간 계산

        std::cout << ", 걸린 시간: " << elapsed.count() << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(time) - elapsed);// 1초 간격을 맞추기 위해 남은 시간 동안 대기
    }

    return 0;
}
