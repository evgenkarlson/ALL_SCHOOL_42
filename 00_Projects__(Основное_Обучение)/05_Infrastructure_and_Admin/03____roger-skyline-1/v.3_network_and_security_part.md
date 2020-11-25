# 42-roger-skyline-1

### V.3 Сеть и безопасность

Вы должны создать пользователя без полномочий `root` для подключения к машине и работы.
```
sudo adduser roger
```

Используйте `sudo` с этим пользователем, чтобы иметь возможность выполнять операцию, требующую специальных прав.
```
sudo usermod -aG sudo roger
```

Чтобы переключиться на вновь созданного пользователя, используйте:
```
su roger
```
_NB: при вводе пароля вы ничего не увидите, это нормально._
Используйте `passwd`, если хотите изменить пароль на более надежный.



Мы не хотим, чтобы вы использовали службу `DHCP` на вашем компьютере. Вам необходимо настроить статический IP-адрес и маску сети в `\30`.
```
```

Вы должны изменить порт службы SSH по умолчанию на любой по вашему выбору. Изменим его на `242`.
```
sudo cat /etc/ssh/sshd_config | grep 'Port ' \
&& sudo chmod 0777 /etc/ssh/sshd_config \
&& sudo sed -i 's/#Port 22/Port 242/g' /etc/ssh/sshd_config /etc/ssh/sshd_config \
&& sudo chmod 0644 /etc/ssh/sshd_config \
&& sudo cat /etc/ssh/sshd_config | grep 'Port '
&& sudo service sshd restart
```

Доступ по `SSH` ДОЛЖЕН осуществляться с использованием публичных ключей. Корневой доступ по `SSH` НЕ должен быть разрешен напрямую, а только с пользователем, который может быть `root`.

На твоем компьютере:
```
mkdir keys
&& umask 077 \
&& wg genkey | tee keys/server_privatekey | wg pubkey > keys/server_publickey \
&& ssh-add keys/server_publickey \
&& cat keys/server_privatekey
```

Скопируйте {content} (содержимое)закрытого ключа, а затем добавте его в виртуальную машину:
```
echo '{content}' > server_privatekey
ssh-add server_privatekey
```

Убедитесь, что ключ теперь присутствует:
```
.ssh/authorized_keys
```

Вы должны установить правила своего брандмауэра на своем сервере только с сервисами, используемыми вне виртуальной машины. Вам нужен только `SSH-доступ`:
```
$ sudo iptables -P INPUT DROP
$ sudo iptables -P OUTPUT DROP
$ sudo iptables -A INPUT -i lo -j ACCEPT
$ sudo iptables -A INPUT -p tcp -m tcp --dport 242 -j ACCEPT
$ sudo iptables -A OUTPUT -o lo -j ACCEPT
$ sudo iptables -A OUTPUT -p tcp --sport 242 -m state --state ESTABLISHED -j ACCEPT
```
_NB: используйте правильный порт `ssh`, который вы ранее изменили_


Кроме того, вы можете отключить вход по паролю, но убедитесь, что `.ssh/authorized_keys` содержит частный ключ.
```
PasswordAuthentication no
```

## Установим защиту `DOS (Denial Of Service Attack)` на открытых портах вашей виртуальной машины.


#### 1: Отбрасываем недопустимые пакеты ####
```
/sbin/iptables -t mangle -A PREROUTING -m conntrack --ctstate INVALID -j DROP 
```

#### 2: Отбрасываем `TCP-пакеты`, которые являются новыми и не являются `SYN` ####
```
/sbin/iptables -t mangle -A PREROUTING -p tcp ! --syn -m conntrack --ctstate NEW -j DROP
```

#### 3: Отбрасываем пакеты `SYN` с подозрительным значением `MSS` ####
```
/sbin/iptables -t mangle -A PREROUTING -p tcp -m conntrack --ctstate NEW -m tcpmss ! --mss 536:65535 -j DROP 
```

#### 4: Блокируем пакеты с поддельными флагами `TCP` ####
```
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,SYN,RST,PSH,ACK,URG NONE -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,SYN FIN,SYN -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags SYN,RST SYN,RST -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,RST FIN,RST -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,ACK FIN -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ACK,URG URG -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ACK,FIN FIN -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ACK,PSH PSH -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL ALL -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL NONE -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL FIN,PSH,URG -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL SYN,FIN,PSH,URG -j DROP
/sbin/iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG -j DROP 
```

#### 5: Блокируем поддельные пакеты ####
```
/sbin/iptables -t mangle -A PREROUTING -s 224.0.0.0/3 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 169.254.0.0/16 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 172.16.0.0/12 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 192.0.2.0/24 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 192.168.0.0/16 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 10.0.0.0/8 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 0.0.0.0/8 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 240.0.0.0/5 -j DROP
/sbin/iptables -t mangle -A PREROUTING -s 127.0.0.0/8 ! -i lo -j DROP 
```

#### 6: Отбрасываем ICMP (обычно этот протокол не нужен) ####
```
/sbin/iptables -t mangle -A PREROUTING -p icmp -j DROP 
```

#### 7: Сбросываем фрагменты во все цепочки ####
```
/sbin/iptables -t mangle -A PREROUTING -f -j DROP 
```

#### 8: Ограничиваем количество подключений на исходный IP ####
```
/sbin/iptables -A INPUT -p tcp -m connlimit --connlimit-above 111 -j REJECT --reject-with tcp-reset 
```

#### 9: Ограничиваем пакеты `RST` ####
```
/sbin/iptables -A INPUT -p tcp --tcp-flags RST RST -m limit --limit 2/s --limit-burst 2 -j ACCEPT
/sbin/iptables -A INPUT -p tcp --tcp-flags RST RST -j DROP 
```

#### 10: Ограничиваем количество новых `TCP-соединений` в секунду для каждого IP-адреса источника ####
```
/sbin/iptables -A INPUT -p tcp -m conntrack --ctstate NEW -m limit --limit 60/s --limit-burst 20 -j ACCEPT
/sbin/iptables -A INPUT -p tcp -m conntrack --ctstate NEW -j DROP 
```

#### 11: Используем `SYNPROXY` на всех портах (отключает правило ограничения подключений) ####
Hidden(Скрытый) - разблокируйте содержимое выше в разделе "Mitigating SYN Floods With SYNPROXY"(«Устранение последствий `SYN-флуда` с помощью `SYNPROXY`»)


------------------------------------------------------------------------------------

## Устанавливаем защиту от сканирования на открытых портах вашей виртуальной машины.

> https://unix.stackexchange.com/questions/345114/how-to-protect-against-port-scanners


Сначала создадим списки `ipset`

```
ipset create port_scanners hash:ip family inet hashsize 32768 maxelem 65536 timeout 600
ipset create scanned_ports hash:ip,port family inet hashsize 32768 maxelem 65536 timeout 6
```

И правила `iptables`

```
iptables -A INPUT -m state --state INVALID -j DROP
iptables -A INPUT -m state --state NEW -m set ! --match-set scanned_ports src,dst -m hashlimit --hashlimit-above 1/hour --hashlimit-burst 5 --hashlimit-mode srcip --hashlimit-name portscan --hashlimit-htable-expire 10000 -j SET --add-set port_scanners src --exist
iptables -A INPUT -m state --state NEW -m set --match-set port_scanners src -j DROP
iptables -A INPUT -m state --state NEW -j SET --add-set scanned_ports src,dst
```

Останавливаем службы, которые вам не нужны для этого проекта.

Вы можете отобразить службы вот так:
```
service --status-all
```

Вам необходимо сохранить следующие службы:
```
ssh
ufw
```

## WIP (booh!)
* Создайте сценарий, который обновляет все источники пакета, а затем ваши пакеты и который записывает все в файл с именем `/var/log/update_script.log`. Создавайте запланированное задание для этого сценария один раз в неделю в 4 часа утра и каждый раз при перезагрузке машины.

* Создайте сценарий для отслеживания изменений файла `/etc/crontab` и отправьте электронное письмо пользователю `root`, если он был изменен. Создавайте запланированную задачу сценария каждый день в полночь.
