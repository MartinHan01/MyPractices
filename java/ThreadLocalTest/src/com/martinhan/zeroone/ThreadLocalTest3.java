package com.martinhan.zeroone;

public class ThreadLocalTest3 {

	private static ThreadLocal<Integer> threadLocal = new ThreadLocal<>();
	static int value = 100;

	public static void main(String[] args) throws InterruptedException {
		Thread aThread = new Thread(){
			@Override
			public void run() {
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				threadLocal.set(value + 200);
				System.out.println("thread ---" + Thread.currentThread() + " value is " + threadLocal.get());
			}
		};

		Thread bThread = new Thread(){
			@Override
			public void run() {
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				threadLocal.set(value + 400);
				System.out.println("thread ---" + Thread.currentThread() + " value is " + threadLocal.get());
			}
		};
		aThread.start();
		bThread.start();
		
	}
}
