#include <iostream>
#include <thread>

std::mutex mymutex;

void func(int id)
{
   for (int i = 0; i < 44; ++i){
      std::lock_guard<std::mutex> guard(mymutex);
      std::cout << "Thread " << id << " is counting " << i << std::endl; 
   }
}

int main(void){

   std::thread th1{func, 1};
   std::thread th2{func, 2};

   mymutex.lock();
   std::cout << "Finished running threads" << std::endl;
   mymutex.unlock();

   th1.join();
   th2.join();

   mymutex.lock();
   std::cout << "End of the main program" << std::endl;
   mymutex.unlock();

   return 1;
}