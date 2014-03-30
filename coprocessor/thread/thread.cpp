
#include "thread.h"
#ifdef NR_USE_THREADS

#include "WPILib.h"

#include <ctime>
#include <typeinfo>

coprocessor::thread::Thread::Thread( void * functionType, void * functionToRun = NULL)
	: stopRequested( false ), running( false ), runThis( functionToRun )
{
	void (*this->runThisFn)() = this->runThis;
}

void * coprocessor::thread::Thread::Start()
{
	if( this->running == false )
	{
		this->running = true;
		pthread_create( &this->thread, 0, &Thread::StartThread, ( void *) this );
	}
	else
	{ 
		printf( "W: Thread is already running." );
	}
}

void coprocessor::thread::Thread::Stop()
{
	if( this->running == true )
	{
		this->running = false;
		this->stopRequested = true;
		pthread_join( this->thread, 0 );
	}
	else
	{
		printf( "W: Thread is not running." );
	}
}

void coprocessor::thread::Thread::Join() throw()
{
	pthread_join( thread, NULL );
}

void coprocessor::thread::Thread::Sleep( double msecs ) throw ()
{
	struct timespec sleep_time, remaining_time;
	sleep_time.tv_nsec = ( int )( msecs * 1000 );

	nanosleep( &sleep_time, &remaining_time );
}

void coprocessor::thread::Thread::StartThread( void * obj )
{
	if( this->runThis == NULL )
	{
		reinterpret_cast<coprocessor::thread::Thread *>( obj )->Run();
	}
	else
	{
		//( void *) * (* runThisFn )() = ( void * ) *this->runThis;
		(* this->runThis )();
		//( *runThisFn )();
	}
}

void coprocessor::thread::Thread::Run()
{
	printf( "Default run method." );
}

#endif
