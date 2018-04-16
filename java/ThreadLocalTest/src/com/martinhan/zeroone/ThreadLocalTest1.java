package com.martinhan.zeroone;

public class ThreadLocalTest1 {
	
	
	public static void main(String[] args) {
		Num1 num = new Num1(100);
		Thread aThread = new Thread(){
			
			@Override
			public void run() {
				try {
					Thread.sleep(100L);
					num.addValue(200);
					System.out.println("thread ---" + Thread.currentThread() + " value is " + num.getValue());
				} catch (InterruptedException e) {
					e.printStackTrace();
				};
			}
		};
		Thread bThread = new Thread(){
			
			@Override
			public void run() {
				try {
					Thread.sleep(100L);
					num.addValue(200);
					System.out.println("thread ---" + Thread.currentThread() + " value is " + num.getValue());
				} catch (InterruptedException e) {
					e.printStackTrace();
				};
			}
		};
		aThread.start();
		bThread.start();
	}
}
