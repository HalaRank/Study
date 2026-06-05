@echo off
 :entry
 echo ---------------------------
 echo 1 进入算命大师
 echo 0 退出程序
 echo ---------------------------
 set /p flag=请输入：
 if %flag%==0 goto :end
 if %flag%==1 goto :function
 if %flag% GTR 1 (
    echo ---------------------------
    echo 请重新输入
    goto :entry
 )
 goto:eof

 :function
 set /p yearmonthday=请输入出生日期： 年月日（例如20040726）
 set "shengxiao=猴鸡狗猪鼠牛虎兔龙蛇马羊"
 set /a year=%yearmonthday:~0,4%
 set /a mod=%year% %% 12
 set monthday=%yearmonthday:~4,4%
 set /a month=%yearmonthday:~4,2%
 set /a day=%yearmonthday:~6,2%

 if %month% LSS 1 (
     echo ---------------------------
     echo 输入的月份不合法,请重新输入
     goto :function
 )

 if %month% GTR 12 (
     echo ---------------------------
     echo 输入的月份不合法,请重新输入
     goto :function
 )

 if %month%==1 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 31 (
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==2 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 29 (
        echo 输入的日期不合法,请重新输入
        goto :function)
 )
 
 if %month%==3 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 31 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==4 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 30 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==5 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 31 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==6 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 30 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==7 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 31 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==8 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 31 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==9 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 30 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==10 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 31 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==11 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 30 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 if %month%==12 (
    if %day% LSS 1 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
    if %day% GTR 31 (
        echo ---------------------------
        echo 输入的日期不合法,请重新输入
        goto :function)
 )

 echo ---------------------------
 if %mod%==0 Echo 你属猴
 if %mod%==1 Echo 你属鸡
 if %mod%==2 Echo 你属狗
 if %mod%==3 Echo 你属猪
 if %mod%==4 Echo 你属鼠
 if %mod%==5 Echo 你属牛
 if %mod%==6 Echo 你属虎
 if %mod%==7 Echo 你属兔
 if %mod%==8 Echo 你属龙
 if %mod%==9 Echo 你属蛇
 if %mod%==10 Echo 你属马
 if %mod%==11 Echo 你属羊
 
 if "%monthday%" LEQ "0119" echo 魔蝎座
 if "%monthday%" GEQ "0120" if "%monthday%" LEQ "0218" echo 水瓶座
 if "%monthday%" GEQ "0219" if "%monthday%" LEQ "0320" echo 双鱼座
 if "%monthday%" GEQ "0321" if "%monthday%" LEQ "0419" echo 白羊座
 if "%monthday%" GEQ "0420" if "%monthday%" LEQ "0520" echo 金牛座
 if "%monthday%" GEQ "0521" if "%monthday%" LEQ "0621" echo 双子座
 if "%monthday%" GEQ "0622" if "%monthday%" LEQ "0722" echo 巨蟹座
 if "%monthday%" GEQ "0723" if "%monthday%" LEQ "0822" echo 狮子座
 if "%monthday%" GEQ "0823" if "%monthday%" LEQ "0922" echo 处女座
 if "%monthday%" GEQ "0923" if "%monthday%" LEQ "1023" echo 天秤座
 if "%monthday%" GEQ "1024" if "%monthday%" LEQ "1122" echo 天蝎座
 if "%monthday%" GEQ "0321" if "%monthday%" LEQ "0419" echo 白羊座
 if "%monthday%" GEQ "1222" echo 魔蝎座
 echo ---------------------------
 goto :entry

 :end
 Pause
