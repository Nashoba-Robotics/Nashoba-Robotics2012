
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
			Thread( void * functionToRun = NULL )
				: stopRequested( false ), running( false ), runThis( functionToRun )
			{
				pthread_mutex_init( &m_mutex );
			}

			~Thread()
			{
				pthread_mutex_destroy( &m_mutex );
			}

			void Start() 
			{
				if( running == false )
				{
					running = true;
					pthread_create( &thread, 0, &Thread::StartThread, this );
				}
				else
				{
					//XXX: printf might not handle *this 
					printf( "W: %s is already running.", *this );
				}
			}

			void Stop()
			{
				if( running == true )
				{
					running = false;
					stopRequested = true;
					pthread_join( &thread, 0 );
				}
				else
				{
					//XXX: printf might not handle *this
					printf( "W: %s is not running.", *this );
				}
			}

		private:
			volatile bool stopRequested;
			volatile bool running;
			void * runThis;
			pthread_mutex_t m_mutex;
			pthread_t thread;
			Thread& operator=( Thread& );
			Thread& operator==( Thread& );

			static void StartThread( void * obj )
			{
				//reinterpret_cast<Thread*>( obj )->Run();
				runThis();
			}

			virtual void Run();
		};
	}
}

#endif
#endif
