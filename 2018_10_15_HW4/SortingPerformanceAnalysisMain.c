/**
 * 작성자 : 김민수
 * 학번 : 20174444
 * 학과 : 컴퓨터소프트웨어공학과
 * 프로그램명 : 04 HW
 * 작성일 : 2018-10-15
 */

#include <stdio.h> // 표준입출력 라이브러리 헤더파일 선언
#include <stdlib.h> // malloc, free함수 사용을 위한 헤더파일 선언
#include <time.h> // clock함수 사용을 위한 헤더파일 선언

/* 사용자 지정 헤더파일 선언
   정렬 함수들을 모아놓은 헤더파일 */
#include "SortingFunction.h"

int main()
{
	int *a;
    // 데이터의 개수만큼 동적 할당할 배열 선언
	int count = 0;
    // 데이터의 개수를 저장할 변수 선언 및 초기화
	int i;
    // 반복문에서 사용할 변수 선언
	clock_t start, finish;
    // 시간을 측정하는데 사용할 clock_t 타입 변수 선언
	double time;
    // 측정한 시간을 저장할 변수 선언

    /* 파일 포인터 fp선언 및 data.txt를 읽기모드로 연다. */
	FILE *fp = fopen("data.txt", "r");

    /* 파일을 여는데에 실패했을 경우 */
	if (fp == NULL)
	{
		printf("FILE OPEN ERROR!\n"); // 예외처리
		return 0; // 메인 함수 종료
	}

    /* 파일에서 데이터를 읽어 오는 상태 출력 */
	printf(" ------------------------------------- \n");
	printf("|        ENTERING DATA IN FILE        |\n");
	printf(" ------------------------------------- \n");

    /* 파일의 끝까지 반복하는 반복문 */
	while (!feof(fp))
	{
		fscanf(fp, " %d", &i); // 파일에서 임시로 데이터를 읽어온다.
		count++; // count 1 증가
	}

    /* 데이터의 개수인 count수 만큼 정수형 배열 동적 할당 */
	a = (int *)malloc(sizeof(int) * count);

	rewind(fp); // 파일 포인터의 위치를 처음으로 돌린다.

    /* 파일의 개수만큼 반복하는 반복문 */
	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);
        // 파일에서 데이터를 읽어와 a[i]에 저장

    /* 입력받은 데이터의 개수를 출력 */
	printf(" ------------------------------------- \n");
	printf("|         DATA ENTRY COMPLETE         |\n");
	printf("|       NUMBER OF DATA : %-8d     |\n", count);
	printf(" ------------------------------------- \n");

    /* 정렬 시작 확인 상태 출력 */
	printf(" ------------------------------------- \n");
	printf("|     START SORTING %8d DATA     |\n", count);
	printf(" ------------------------------------- \n");

	/* 기수 정렬 알고리즘 실행 */
	start = clock(); // 시작 시간 측정
	radix_sort(a, count, 4); // 기수 정렬 함수 호출
	finish = clock(); // 종료 시간 측정

	time = (double)(finish - start) / CLOCKS_PER_SEC;
	// 저장된 값을 이용하여 걸린 시간 계산

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|              Radix Sort             |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	rewind(fp);

	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);

	/* 병합 정렬 알고리즘 실행 */
	start = clock();
	merge_sort(a, 0, count - 1);
	finish = clock();

	time = (double)(finish - start) / CLOCKS_PER_SEC;

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|              Merge Sort             |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	rewind(fp);

	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);

	/* 히프 정렬 알고리즘 실행 */
	start = clock();
	heap_sort(a, count);
	finish = clock();

	time = (double)(finish - start) / CLOCKS_PER_SEC;

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|              Heap  Sort             |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	rewind(fp);

	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);

	/* 퀵 정렬 알고리즘 실행 */
	start = clock();
	quick_sort(a, 0, count - 1);
	finish = clock();

	time = (double)(finish - start) / CLOCKS_PER_SEC;

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|              Quick  Sort            |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	rewind(fp);

	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);

	/* 버블 정렬 알고리즘 실행 */
	start = clock();
	bubble_sort(a, count);
	finish = clock();

	time = (double)(finish - start) / CLOCKS_PER_SEC;

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|              Bubble  Sort           |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	rewind(fp);

	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);

	/* 삽입 정렬 알고리즘 실행 */
	start = clock();
	insertion_sort(a, count);
	finish = clock();

	time = (double)(finish - start) / CLOCKS_PER_SEC;

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|            Insertion  Sort          |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	rewind(fp);

	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);

	/* 선택 정렬 알고리즘 실행 */
	start = clock();
	selection_sort(a, count);
	finish = clock();

	time = (double)(finish - start) / CLOCKS_PER_SEC;

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|            Selction  Sort           |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	rewind(fp);

	for (i = 0; i < count; i++)
		fscanf(fp, " %d", &a[i]);

	/* 셸 정렬 알고리즘 실행 */
	start = clock();
	shell_sort(a, count);
	finish = clock();

	time = (double)(finish - start) / CLOCKS_PER_SEC;

	/* 정렬 완료 상태 및 걸린 시간 출력 */
	printf(" ------------------------------------- \n");
	printf("|              Shell  Sort            |\n");
	printf("|    FINISHED SORTING %8d DATA   |\n", count);
	printf("|        TIME TAKEN : %-8.2f s      |\n", time);
	printf(" ------------------------------------- \n\n\n");

	free(a); // 동적 할당한 배열 메모리 할당 해제
	fclose(fp); // 열어준 파일 포인터 fp를 닫아준다.

	return 0; // 메인 함수 종료
}
