
#define NR_USE_THREADS
#ifdef NR_USE_THREADS

#pragma once

#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

namespace coprocessor
{
	namespace thread
	{
		class Thread
		{
		public:
			Thread( void *, void(*));
			void * Start();
			void Stop();
			void Join() throw();
			static void Sleep( double ) throw();

		protected:
			volatile bool stopRequested;
			volatile bool running;
			void * runThis;
			pthread_t thread;

			void StartThread( void *);
			virtual void Run();
			
		private:
			void (* runThisFn)();
			coprocessor::thread::Thread& operator=( coprocessor::thread::Thread& );
			coprocessor::thread::Thread& operator==( coprocessor::thread::Thread& );
		};
	}
}

#endif
#endif
