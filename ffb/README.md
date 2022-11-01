https://forum.il2sturmovik.ru/topic/12943-%D0%BD%D0%B0%D1%80%D0%BE%D0%B4%D0%BD%D1%8B%D0%B9-ffb-%D0%B2%D0%BE%D0%B7%D0%BC%D0%BE%D0%B6%D0%BD%D0%BE/



Слушай, а возьми ка в JoyTester порисуй круги да покажи нам, хоть наглядно глянем.



Двигатели
{
    Мотор от гироскутеоа Vs BLDC vs трех-фазники
    {
        кто-то ещё использует именно BLDC: https://www.youtube.com/watch?v=Qy0m2p0FXnk
    }


    propeler {
        - BLDC

        Да рассматривался, но ТС упорно смотрит в сторону BLDC. Кроме того на вал двигателя шуруповерта запрессована шестерня, что мешает надеть шкив для ременной передачи, а родной планетарный редуктор, боюсь, будет люфтить. 

        propeler {
            Текущую реализацию делаю под мотор 60kV (они у меня в наличии) с питанием от компьютерного блока питания на 600W. Линия 12V такого блока дает 50А. Значит 25А на ось при максимальной загрузке можно получить. Мотор на 25 амперах держит момент около 3.7Nm.  С ременной передачей 1:5 планирую получить 18.5N. На ручке 0.3м в пике можно получить под 6кг усилие в пике. Мне кажется этого более чем с головой! 

            Если кто хочет сэкономить на моторах, то следующим шагом будет механика под моторки от гироскутера. Их цена меньше 20 долларов за штуку на барахолке. По характеристикам выдают до 12Nm на 20 амперах. Можно использовать даже без редуктора. 
             
            Да, я рассматриваю BLDC. Потому что это решение которое написано и адекватно работает без лишних бубнов.  Плюс можно обойтись минимальными отношениями редуктора в случае если он нужен.


            !!! его(Пропеллера) мотор: https://alienpowersystem.com/shop/brushless-motors/50mm/aps-5065-outrunner-brushless-motor-60kv-1800w/
        }


https://youtu.be/djsYNXpIq_I


       [P32] Чего то не работает. Пользуюсь версией выложенной по https://github.com/gavazquez/bldc-ffb-joystick, поскольку ваша ветка в гитхаб недоступна.
       [P32] https://youtu.be/MUK2omoil2U  Так вот он какой! FFB джойстик от VKB! 


        l3VGV {
            https://github.com/nervTeh/ForceFeedback-core-library
            https://github.com/denisn73/JoyFFB


        }
https://github.com/Ultrawipf/OpenFFBoard/tree/master/Firmware
https://github.com/SimuCUBE/SimuCUBE-OpenSource-Firmware
https://github.com/nervTeh/ForceFeedback-core-library
https://github.com/hoantv/VNWheel 
    }


    Magenta {
        https://forum.il2sturmovik.ru/topic/12943-%D0%BD%D0%B0%D1%80%D0%BE%D0%B4%D0%BD%D1%8B%D0%B9-ffb-%D0%B2%D0%BE%D0%B7%D0%BC%D0%BE%D0%B6%D0%BD%D0%BE/page/37/#comment-882080
    }



    моторы
    {
        BLDC: https://www.freerchobby.cc/collections/brushless-motor/products/bldc-belt-motor-mp-6384-4000w-for-electric-skateboard
    }



    Примеры FFB джоев
    {
        {
            Youtube: https://www.youtube.com/watch?v=MUK2omoil2U
            Github:  https://github.com/aurism/proteus-simpit
        }

        {
            https://github.com/gavazquez/bldc-ffb-joystick
        }
    }


    {
        MYCYJIbMAHUH

            Пользователь
            MYCYJIbMAHUH
                2k
        Posted August 11 (edited)
            On 8/11/2022 at 9:52 AM, Crobat said:
            Ну ок, раз на текущий момент никто не готов озвучить ценник, то ждем дальше.
        Могу твёрдо сказать о себестоимости  по некоторым компонентам.
        Купил на Авито два мотор колеса-3000руб.
        Отрезать,согнуть,покрасить корпус девайса-3000-4000руб.
        Метрический крепёж оксидный\нержавеющий(винты.гайки)-1000руб.
        Токарные работы в районе пяти-семи тысяч.руб
        И конечно самый главный вопрос-сколько попросить за сборку девайса.Моя жена говорит-что я не ценю свой труд и мало беру за работу.

        Edited August 11 by MYCYJIbMAHUH 
    }

    {
        AlienPower APS 5065 на 60kV. Дает около 4.2 Nm на 25 амперах. 
        {
            propeler: Сейчас тетстирую на мелочи. Для конечного можно использовать например двигатели от гироскутера. Такие двигатели стоят относительные копейки для их характеристик. Выдают до 12 Nm при 20 амперах тока. С редукцией(ремень или простой рычаг с плечами 1:2)  дает уже прилично хорошее усилие на ручке даже для подстульника. 
            Если хочется компактнее то прийдется использовать что-то подороже, типа AlienPower APS 5065 на 60kV. Дает около 4.2 Nm на 25 амперах.  На прямой передаче маловато для подстульника, но хватит если использовать ременной редуктор. 
        }


    }

 

}

ffb для авторуля
{
    https://forum.simracing.su/topic/3487-diy-ffb-steering-wheel/
    идея РУС с ffb была позаимствована именно оттуда
    {
        Johnet:
            Вот тут люди рули делают. Пока все мои мысли оттуда:
            https://forum.simracing.su/topic/3487-diy-ffb-steering-wheel/ 
    }


    ещё один руль
    {
        https://cxem.net/mc/mc207.php
    }
}


