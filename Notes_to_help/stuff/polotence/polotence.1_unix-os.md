# Unix OS #
[Unix shell](https://ru.wikipedia.org/wiki/Командная_оболочка_Unix) - (комaндная оболочка Unix, часто просто «шелл» или «sh») — командный интерпретатор, используемый в операционных системах семейства Unix. В нем пользователь может либо давать команды операционной системе по отдельности, либо запускать скрипты, состоящие из списка команд. В MacOS и Linux стандартной командой оболочкой является bash (одна из разновидностей оригинального shell).

Вот 3 разных пути ведущих к тому, чтобы понять как работать с bash:

---

### 1. Unix OS: Windows 10 subsystem for Linux ###
* Открываем Start menu в Windows 10 и ищем PowerShell, запускаем его от имени администратора
* Прописываем в PowerShell чтобы активировать Bash в Windows и настроить ее под себя:
```
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```
* Скачиваем Linux Ubuntu из Microsoft Store и запускаем ее. Она должна обновиться!
* Вероятнее всего, что некоторые пакеты вы установить не сможете, поэтому читаем вывод в терминал и ищем решение. Я решил проблему так:
  * Переключаемся в root ```sudo su``` и скачиваем обновления: ```apt-get update```
  * Устанавливаем для теста gcc: ```sudo apt install gcc```. Если установка прошла успешно, то значит можно работать.

---

### 2. - Unix OS: VMware - Linux Ubuntu ###
* Скачиваем VMware (ищите на торрентах repack, могу лишь посоветовать nnm-club.ru).
* Скачиваем [Ubuntu Desktop](https://ubuntu.ru/get).
* Устанавливаем виртуалку в VMware, ничего сложного нету, главное выделите 20 гб свободного места.
* Сразу смело ставьте эти пакеты, через терминал:
   ```
   sudo apt install gcc && git && make && vim && gnome-tweak-tool
   ```
   gnome-tweak-tool нужна для изменения раскладки на alt-shift: заходим в Tweaks → KeyBoard&Mouse → Additional Layout Option → Switch to, меняем на нужную раскладку

---

### 3. - Unix OS: VMware - macOS Sierra ###
macOS Sierra - для тех, кто хочет понять с какой OS мы будем работать в школе.
1) Образ macOS [Sierra v.10.12.5 (16F73)](https://nnmclub.to/forum/viewtopic.php?t=1151080)
2) [Установка](https://youtu.be/WYkgtMEDUXQ) macOS Sierra VMWare Workstation 
3) У кого bootloop при старте, пишем в файле macOS 10.13.vmx
```
cpuid.1.eax = "0000:0000:0000:0001:0000:0110:1010:0101"
smc.version = "0"
```
4) [Настройка клавиатуры](https://o7planning.org/ru/11555/how-to-use-windows-like-shortcuts-in-mac-os-virtual-machine)