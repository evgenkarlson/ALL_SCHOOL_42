# roger-skyline-1 #

## HASHSUM
`d5b6d5ef1591771e0e182ea3f3ad576f  roger-skyline-1.vhd`

## I.   Создание виртуальной машины
1.  Скачать и установить `VirtualBox 6.1.x`
2.  Загрузить образ `debian-10.3.0-amd64-netinst.iso`
3.  Создать виртуальную машину в VirtualBox со следующими параметрами:
    1.  Имя - `roger-skyline-1`
    2.  Папка машины - `/home/sselusa/Projects/roger-skyline-1`
    3.  Тип - `Linux`
    4.  Версия - `Debian (64-bit)`
    5.  Объем оперативной памяти - `1024 Мб`
    6.  Создать динамический виртуальный жесткий диск - `VHD`
    7.  Указать размер жесткого диска - `8 Гб`

## II.  Настройка виртуальной машины
1.  Общие - Дополнительно:
    1.  Общий буфер обмена - `двунаправленный`
    2.  Функция Drag'n'Drop - `двунаправленный`
2.  Носители:
    1.  Контроллер: IDE - Оптический привод - выбрать образ `debian-10.3.0-amd64-netinst.iso`
3.  Сеть:
    1.  Тип подключения - `Сетевой мост`

## III. Установка дистрибутива
1.  Выбрать язык - `English`
2.  Выбрать страну - `Other` - `Europe` - `Russian Federation`
3.  Выбрать раскладку клавиатуры - `United States - en_US.UTF-8` - `American English`
4.  Имя компьютера - `roger-skyline-1`
5.  Имя домена - `msk.21-school.ru`
6.  Пароль суперпользователя - `42`
7.  Полное имя пользователя - `Roger Skyline`
8.  Имя учетной записи - `roger`
9.  Пароль учетной записи roger - `21`
10. Часовой пояс - `Moscow+00 - Moscow`
11. Метод разметки - `Manual`
12. Выбрать диск `SCSI3 (0,0,0) (sda) - 8.6 GB ATA VBOX HARDDISK` и согласиться на создание новой таблицы разметки
13. Выбрать незанятое пространство - `FREE SPACE`
14. Создать новый `Primary` раздел - `4.2 Гб`, с начала диска (`Beginning`)
15. Сохранить изменения
16. Выбрать незанятое пространство - `FREE SPACE`
17. Выбрать автоматическую разметку свободного пространства с выделением раздела `/home`
18. Закончить разметку и записать изменения на диск
19. Отменить сканирование другого диска
20. Выбрать зеркало архива Debian - `Russian Federation` - `mirror.corbina.net`
21. Не заполнять информацию о HTTP-прокси и продолжить установку
22. Отклонить участие в опросе популярности пакетов
23. Из программного обеспечения установить только `SSH server` и `standard system utilities`
24. Установить системный загрузчик GRUB в `/dev/sda`
25. Продолжить установку, носитель извлечётся автоматически

## IV.  Подключение к серверу по SSH
1.  Узнать временный IP-адрес виртуальной машины:
    ```
    ip a
    ```
2.  Подключиться к серверу с клиента:
    ```
    ssh roger@192.168.0.XX
    roger@192.168.0.XX's password: 21
    ``

## V.   Настройка пользователя
1.  Зайти в `root` на сервере:
    ```
    roger-skyline-1 login: root
    Password: 42
    cd /
    ```
2.  Установить `sudo`, `vim`:
    ```
    apt update && apt upgrade -y
    apt install sudo vim -y
    ```
3.  Добавить roger в группы `adm` и `sudo`:
    ```
    usermod -a -G adm,sudo roger
    ```
4.  Проверить правильность настройки пользователя roger:
    ```bash
    groups roger
    # roger : roger ADM cdrom floppy SUDO audio dip video plugdev netdev bluetooth
    ```

## VI.  Настройка сетевого интерфейса
1.  Отредактировать конфигурационный файл сетевого интерфейса:
    ```
    vim /etc/network/interfaces
    ```
    1.  Изменить строку `iface enp0s3 inet dhcp` на `iface enp0s3 inet static`
    2.  Добавить следующие строки:
    ```bash
        address     192.168.0.2 # Статический локальный IP-адрес
        netmask     255.255.255.252 # Маска подсети \30
        gateway     192.168.0.1 # Гейт (в этом случае - роутер)
        nameserver  8.8.8.8 # DNS-сервер (в этом случае - Google DNS)
    ```
2.  Перезагрузить сервер:
    ```
    reboot
    ```
3.  Зайти в `root` на сервере:
    ```
    roger-skyline-1 login: root
    Password: 42
    cd /
    ```

## VII. Настройка SSH
1.  Отредактировать конфигурационный файл SSH:
    ```
    vim /etc/ssh/sshd_config
    ```
    1.  Изменить строку `#Port 22` на `Port 2121`
    2.  Изменить строку `#PermitRootLogin prohibit-password` на `PermitRootLogin no`
    3.  Изменить строку `#PubkeyAuthentication yes` на `PubkeyAuthentication yes`
    4.  Изменить строку `#AuthorizedKeysFile .ssh/authorized_keys .ssh/authorized_keys2` на `AuthorizedKeysFile .ssh/authorized_keys`
2.  Перезапустить SSH:
    ```
    service sshd restart
    service sshd status
    ```
3.  На `клиенте` сгенерировать SSH ключ:
    ```
    ssh-keygen
    ```
4.  На `клиенте` добавить ключ на сервер:
    ```
    ssh-copy-id -i ~/.ssh/id_rsa.pub roger@192.168.0.2 -p 2121
    ```
5.  Отредактировать на `сервере` конфигурационный файл SSH:
    ```
    vim /etc/ssh/sshd_config
    ```
    1.  Изменить строку `#PasswordAuthentication yes` на `PasswordAuthentication no`
    2.  Изменить строку `#PermitEmptyPasswords no` на `PermitEmptyPasswords no`
6.  Перезапустить SSH:
    ```
    service sshd restart
    service sshd status
    ```
7.  На `клиенте` проверить подключение к серверу:
    ```
    ssh roger@192.168.0.2 -p 2121
    ```

## VIII.    Настройка фаервола
1.  Зайти в `root` на сервере:
    ```
    roger-skyline-1 login: root
    Password: 42
    cd /
    ```
2.  Установить `ufw`:
    ```
    apt install ufw -y
    ```
3.  Установить правила фаервола:
    ```bash
    ufw default deny incoming # Заблокировать весь входящий трафик
    ufw default allow outgoing # Разблокировать весь исходящий трафик
    ufw allow 443 # Разблокировать HTTPS
    ufw allow 80/tcp # Разблокировать HTTP
    ufw allow 2121/tcp # Разблокировать SSH
    ```
4.  Активировать фаервол:
    ```
    ufw enable
    ```
5.  Проверить фаервол:
    ```
    ufw status verbose
    ```
6.  Перезагрузить сервер:
    ```
    reboot
    ```
7.  Зайти в `root` на сервере:
    ```
    roger-skyline-1 login: root
    Password: 42
    cd /
    ```

## IX.  Защита от DoS
1.  Установить `apache2`:
    ```
    apt install apache2 -y
    ```
2.  Установить `fail2ban`:
    ```
    apt install fail2ban -y
    ```
3.  Создать локальную конфигурацию `fail2ban`:
    ```
    vim /etc/fail2ban/jail.d/jail-debian.local
    ```
    со следующим содержанием:
    ```
    [DEFAULT]
    bantime  = 10m
    findtime  = 10m
    maxretry = 5

    [sshd]
    enabled = true
    port = 2121
    maxretry = 3
    findtime = 300
    bantime = 600
    logpath = %(sshd_log)s
    backend = %(sshd_backend)s

    [http-get-dos]
    enabled = true
    port = http,https
    filter = http-get-dos
    logpath = /var/log/apache2/access.log
    maxretry = 300
    findtime = 300
    bantime = 600
    action = iptables[name=HTTP, port=http, protocol=tcp]
    ```
4.  Создать фильтр `http-get-dos`:
    ```
    vim /etc/fail2ban/filter.d/http-get-dos.conf
    ```
    со следующим содержанием:
    ```
    [Definition]
    failregex = ^<HOST> -.*"(GET|POST).*
    ignoreregex =
    ```
5.  Перезапустить сервисы `ufw` и `fail2ban`:
    ```
    ufw reload
    service fail2ban restart
    ```
6.  Активировать `fail2ban`:
    ```
    systemctl enable fail2ban
    ```
7.  Проверить `fail2ban`:
    ```
    systemctl status fail2ban
    iptables -L
    ```
8.  Логи хранятся в `/var/log/fail2ban.log`

## X.   Защита от сканирования портов
1.  Установить `portsentry`:
    ```
    apt install portsentry
    ```
2.  Отредактировать `/etc/default/portsentry`:
    ```
    TCP_MODE="atcp"
    UDP_MODE="audp"
    ```
3.  Отредактировать `/etc/portsentry/portsentry.conf`:
    ```
    BLOCK_TCP="1"
    BLOCK_UDP="1"
    ```
    Раскомментировать строку `KILL_ROUTE="/sbin/iptables -I INPUT -s $TARGET$ -j DROP"`

    Закоментировать строку `#KILL_ROUTE="/sbin/route add -host $TARGET$ reject"`
4.  Перезагрузить `portsentry`:
    ```
    service portsentry restart
    ```
5.  Проверить `portsentry`:
    ```
    service portsentry status
    ```
6.  Проверить все открытые порты и приложения, использующие их:
    ```
    lsof -i -P
    ```

## XI.  Отключение лишних сервисов
1.  Проверить все процессы:
    ```
    systemctl list-units --type service --all
    ```
2.  Проверить все включенные процессы:
    ```
    systemctl list-unit-files --type service | grep enabled
    ```
3.  Отключить все сервисы:
    ```
    systemctl disable SERVICE
    ```
    кроме
    ```bash
    apache2.service                        enabled # Веб-сервер
    apparmor.service                       enabled # Контроль доступа
    autovt@.service                        enabled # Логин
    cron.service                           enabled # Cron
    dbus-org.freedesktop.timesync1.service enabled # Серверное время
    fail2ban.service                       enabled # fail2ban
    getty@.service                         enabled # Логин
    networking.service                     enabled # Сетевой интерфейс
    rsyslog.service                        enabled # Логи
    ssh.service                            enabled # SSH
    sshd.service                           enabled # SSHD
    syslog.service                         enabled # Логи
    systemd-fsck-root.service              enabled-runtime # Проверка системных файлов
    systemd-timesyncd.service              enabled # Синхронизация времени
    ufw.service                            enabled # Фаервол
    ```

## XII. Скрипт обновления пакетов
1.  Зайти в `root` на сервере:
    ```
    roger-skyline-1 login: root
    Password: 42
    cd /
    ```
2.  Создать директорию `scripts`:
    ```
    mkdir scripts && cd scripts
    ```
3.  Создать скрипт `updater.sh`:
    ```
    vim updater.sh
    ```
    со следующим содержанием:
    ```bash
    #!/bin/bash
    set -e

    updater(){
        echo $(date) >> /var/log/update_script.log;
        sudo apt update -y >> /var/log/update_script.log;
        sudo DEBIAN_FRONTEND=noninteractive apt upgrade -y >> /var/log/update_script.log;
    };

    updater;
    ```
4.  Установить разрешения на созданный скрипт:
    ```
    chmod 755 updater.sh
    ```
5.  Добавить запуск скрипта в расписание `cron`:
    ```
    crontab -e
    ```
    в открывшемся редакторе вписать:
    ```bash
    SHELL=/bin/bash
    PATH=/sbin:/bin:/usr/sbin:/usr/bin

    0 4 * * 0 sudo /scripts/updater.sh # Запуск каждую неделю в 4 часа ночи
    @reboot sudo /scripts/updater.sh # Запуск после перезагрузки сервера
    ```
## XIII.    Отслеживание изменений crontab
1.  Установить `sendmail`:
    ```
    apt install sendmail -y
    ```
2.  Создать скрипт `cronguard.sh` в директории `/scripts`:
    ```
    vim cronguard.sh
    ```
    со следующим содержанием:
    ```bash
    #!/bin/bash

    DIFF="$(diff /var/spool/cron/crontabs/root /var/spool/cron/crontabs/root.back)"
    cat /var/spool/cron/crontabs/root > var/spool/cron/crontabs/root.back

    if [ "$DIFF" != "" ]
    then
        echo "Crontab has been modified!" | sendmail root;
    fi;
    ```
3.  Установить разрешение на созданный скрипт:
    ```
    chmod 755 cronguard.sh
    ```
4.  Добавить запуск скрипта в расписание `cron`:
    ```
    crontab -e
    ```
    в открывшемся редакторе вписать:
    ```bash
    0 0 * * * sudo /scripts/cronguard.sh # Запуск каждый день в полночь
    ```
5.  Создать резервную копию `crontab`:
    ```
    cat /var/spool/cron/crontabs/root > var/spool/cron/crontabs/root.back
    ```
6.  Прочитать почту:
    ```
    cat /var/mail/root
    ```
    или
    ```bash
    cat /var/mail/roger # Если в /etc/aliases прописано root: roger
    ```

## XIV. Развертывание WEB-приложения
1.  Скопировать содержимое своего WEB-приложения в `/var/www/html/` на сервере
    ```
    scp -P 2121 index.html roger@192.168.0.2:/var/www/html
    ```

## XV.  Настройка SSL
1.  Создать SSL-сертификат:
    ```
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/apache-selfsigned.key -out /etc/ssl/certs/apache-selfsigned.crt
    ```
    ```
    Country Name (2 letter code) [AU]: RU
    State or Province Name (full name) [Some-State]: Moscow
    Locality Name (eg, city) []: Moscow
    Organization Name (eg, company) [Internet Widgits Pty Ltd]: Roger Skyline
    Organizational Unit Name (eg, section) []:
    Common Name (e.g. server FQDN or YOUR name) []: roger
    Email Address []: roger@192.168.0.2
    ```
2.  Создать файл `ssl-params.conf`:
    ```
    vim /etc/apache2/conf-available/ssl-params.conf
    ```
    со следующим содержанием:
    ```
    SSLCipherSuite EECDH+AESGCM:EDH+AESGCM:AES256+EECDH:AES256+EDH
    SSLProtocol All -SSLv2 -SSLv3 -TLSv1 -TLSv1.1
    SSLHonorCipherOrder On
    Header always set X-Frame-Options DENY
    Header always set X-Content-Type-Options nosniff
    SSLCompression off
    SSLUseStapling on
    SSLStaplingCache "shmcb:logs/stapling-cache(150000)"
    SSLSessionTickets Off
    ```
3.  Отредактировать файл `default-ssl.conf`:
    ```
    vim /etc/apache2/sites-available/default-ssl.conf
    ```
    и изменить:
    ```
    ServerAdmin roger@192.168.0.2
    ServerName  192.168.0.2

    SSLCertificateFile      /etc/ssl/certs/apache-selfsigned.crt
    SSLCertificateKeyFile   /etc/ssl/private/apache-selfsigned.key
    ```
4.  Отредактировать файл `000-default.conf`:
    ```
    vim /etc/apache2/sites-available/000-default.conf
    ```
    добавить строку:
    ```
    Redirect permanent "/" "https://192.168.0.2/"
    ```
5.  Донастроить фаервол:
    ```
    ufw allow 'WWW Full'
    ufw delete allow 'WWW'
    ```
6.  Сохранить изменения:
    ```
    a2enmod ssl
    a2enmod headers

    a2ensite default-ssl
    a2enconf ssl-params

    apache2ctl configtest

    systemctl restart apache2
    ```

## XVI. Автоматизация развертывания
1.  Создать скрипт `deployer.sh`:
    ```
    vim /scripts/deployer.sh
    ```
    со следующим содержанием:
    ```
    #!/bin/bash

    DIFF=$(diff /temp/index.html /var/www/html/index.html)
    if [ "$DIFF" != "" ]; then
        cat /var/html/index.html > /temp/index.html
        cp /temp/example.html /var/www/html/index.html
        echo "index.html changed!" | sendmail root
    fi
    ```
2.  Установить разрешение на созданный скрипт:
    ```
    chmod 755 /scripts/deployer.sh
    ```
3.  Добавить запуск скрипта в расписание `cron`:
    ```
    crontab -e
    ```
    в открывшемся редакторе вписать:
    ```bash
    0 0 * * * sudo /scripts/deployer.sh # Запуск каждый день в полночь
    ```
4.  Создать директорию `temp`:
    ```
    mkdir /temp
    ```
5.  Скопировать `index.html` в `temp`:
    ```
    cp /var/www/html/index.html /temp/index.html
    ```

## XVII.    Тестирование
1.  Проверить группы пользователя `roger`:
    ```
    groups roger
    ```
2.  Проверить настройки `сетевого интерфейса`:
    ```
    cat /etc/network/interfaces
    ping 21-school.ru
    ```
3.  Проверить настройки `SSH`:
    ```
    cat /etc/ssh/sshd_config
    ```
4.  Проверить настройки фаервола `ufw`:
    ```
    ufw status verbose
    ```
5.  Проверить найстройки `fail2ban`:
    ```
    iptables -L
    ```
6.  Проверить все открытые порты и приложения, использующие их:
    ```
    lsof -i -P
    ```
7.  Проверить все включенные процессы:
    ```
    systemctl list-unit-files --type service | grep enabled
    ```
8.  Проверить `crontab`:
    ```
    cat /var/spool/cron/crontabs/root
    ```
    или
    ```
    crontab -e
    ```
9.  Проверить почту:
    ```
    cat /var/mail/root
    ```
    или
    ```bash
    cat /var/mail/roger # Если в /etc/aliases прописано root: roger
    ```
10. Проверить сайт:
    1.  Зайди в браузер
    2.  Ввести http://192.168.0.2/
    3.  Проверить переадрессацию на https
    4.  Проверить наличие сертификата

## XVIII.   Получение хеш-суммы
1.  Сделать backup виртуальной машины:
    ```
    cp roger-skyline-1.vhd roger-skyline-1.vhd.back
    ```
2.  Записать hash в файл `hashsum`:
    ```
    md5sum roger-skyline-1.vhd > ../hashsum
    ```
