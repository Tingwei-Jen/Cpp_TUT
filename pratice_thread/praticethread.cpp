#include <thread>
#include <stdio.h>
#include <atomic>
#include <mutex>
#include <condition_variable>

int value[10] = {0,1,2,3,4,5,6,7,8,9};
std::atomic<int> value2(0);
std::mutex gMutex;

void producer(){ 
  while(1){
  	std::lock_guard<std::mutex> mLock( gMutex );
    value2 = value2.load()+1;
    printf("fuck ");
  }
}
void consumer(){
  while(1){
    std::lock_guard<std::mutex> mLock( gMutex );
    printf("%d  ", value2.load());
  }
}


std::condition_variable cv;
void producer2(){
  while(1){
    std::unique_lock<std::mutex> mLock( gMutex );  
    cv.notify_one();
    cv.wait(mLock);    
    value2 = value2.load()+1;
    printf("fuck \n");
  }
}
void consumer2(){
  while(1){
    std::unique_lock<std::mutex> mLock( gMutex );
    cv.notify_one();
    cv.wait(mLock); 
    printf("%d  \n", value2.load());
  }
}

int main(){

  std::thread t2(consumer2);
  std::thread t1(producer2);
  
  t1.join();
  t2.join();
}