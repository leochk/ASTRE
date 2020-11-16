#include "wdlib.h"
#include "types.h"

void wd_threadbody();
extern struct timespec start_timespec;


int WD_ALARM=-1; 
sigset_t WD_sigset;
pthread_t WD_thread_Id; 

int global_init_wd()
{
  struct sched_param param;
  pthread_attr_t     attr;
  int sys_ret;
  
  // First initialize ssynchronisation between task and WD thread to
  // avoid crashes
  sigemptyset(&WD_sigset);
  sigaddset (&WD_sigset, SIGRTMIN);
  WD_ALARM=SIGRTMIN;
  sigprocmask (SIG_BLOCK, &WD_sigset, NULL);
  
  // then init and start WD thread 

  //return
  return E_OK; 
}

void wd_recovery()
{
  printf("TODO recovery\n");
}

void  wd_threadbody()
{
  // variable used to store the id of the signal that wake up sigwait. 
  siginfo_t caught ; 
  
  // wait watch dog signal (use sigwaitinfo) 

  // call recovery function
  wd_recovery(); 	 

  //return
  return;
}

int local_init_wd(wd_desc_t * wd, periodic_thread_config_t * td)
{
  struct sigevent sigev;
  int ret ;
  static int wd_num; 
  if (wd==0) {printf("error wd init");}
  wd->wd_alrm=WD_ALARM;
  wd->task_descriptor=td;

  // create timer for throwing signal wd->wd_alrm when 
  // wd->timer_id expires

  // return
  return ret ;
}

int set_wd( wd_desc_t * wd)
{
  // duration represent the amount of milliseconds before wd exprire
  // transform duration into absolute time against wd timer
 
  // define itimerspec timerDef:
  // recall that it contains two timespec structs  
  // itinterval should be Zero (e.g. both subfield equal to 0, 
  // and itvalue is used as the absolute time of 
  // the current deadline of the task 
  struct itimerspec* timerDef; 
  timerDef= &wd->tDef;
 
  // initialize first it_interval with zero values 


  // compute next absolute deadline from task config struct 


  //enable timer to wake up watchdog thread in case of deadline miss
  
  // return
  return 0;
} 

int cancel_wd( wd_desc_t * wd){
 // call to settime in order to to desarm the timeout (by setting
 // its it_value to zero).
}
