package ThirdStep.ControlFlow.Thread;





public class Main {

    public static void main(String[] args) {
        System.out.println("Hello from the main thread.");

        Thread anotherThread = new AnotherThread();
       // anotherThread.start();

        anotherThread.setName("==Another Thread");

        // check the output of these two
//        anotherThread.start();
//        anotherThread.run();


        new Thread() {
            public void run() {
                System.out.println("Hello from the anonymous class thread");
            }
        }.start();

        Thread myRunnableThread = new Thread(new MyRunnable());
        myRunnableThread.start();

        // using anonymous

        Thread myRunnableThread_1 = new Thread(new MyRunnable(){
            @Override
            public void run() {
                super.run();
            }
        });
        myRunnableThread_1.start();

        Thread myRunnableThread_2 = new Thread(new MyRunnable(){
            @Override
            public void run() {
                System.out.println("Hello from the anonymous \n");
            }
        });
        myRunnableThread_2.start();

        // so don't call the run method explicitly

        // if we call the run method explicitly then new thread will not be created
        // and the run will executed on the calling method thread

 //        anotherThread.interrupt();

        Thread myRunnableThread_3 = new Thread(new MyRunnable(){
            @Override
            public void run() {
                System.out.println("Hello from the anonymous 3 \n");
                try { // we can pass timeout val
                    anotherThread.join(5000); // myRunnableThread_3 is going to wait for anotherthread to terminate then
                    // will start execution
                    System.out.println("another thread terminated or timedOut so i am running again");
                } catch (InterruptedException e){
                    System.out.println("I couldn't wait after all as i was Interupted");
                }
            }
        });
        myRunnableThread_3.start();



        System.out.println("Hello again from the main thread.");

    }
}
