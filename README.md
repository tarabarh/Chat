# Chat
Разработал Кочетков Алексей. Группа CPLUS-17.

Для итогового проекта по Блоку «Основные конструкции C++» был разработан чат с возможностью обмена личными сообщениями,
а так же обмена сообщениями между всеми участниками чата одновременно.

В проекте были реализованы следующие классы:
1) Account - создаёт учётные записи участников чата. В нём хранятся имя (_name), логин (_nickname), пароль (_password),
   а также контейнер (_message) хранящий указатели на личные сообщения пользователей.
   Реализованы функции: 
   - функция проверки (сравнения) пароля и логина (ComparePassword, CompareNickname) с передаными им данными;
   - функция создания и добавления нового сообщения (AddMessage) в массив _message;
   - функция фильтрации личных сообщений с другим пользователем и вызова функции их вывода вывода (PrintPrivate).
2) Message - создаёт сообщение хранящие текст (_text), отправителя (_from) и получателя (_for). Реализована функция
   вывода сообщения в консоль (Print).
3) Server - отвечает за хранение всех указателей учетных записей пользователей в массиве (_accounts), указатель на вошедшего 
   в чат пользователя (_now) и контейнер (_message_everyone) хранящий указатели на сообщения в общем чате.
   Реализованы функции:
   - функция регистрации (Registration);
   - функция входа по логину/паролю (Login);
   - функция выхода из учетной записи (Logout);
   - функция механизма общего чата (EnterChatAll);
   - функция механизма личного чата (Chat);
   - функция входа в личный чат и выбора собеседника (EnterPrivateChat); 
   - функция задания вывода сообщений общего чата в консоль (PrintChatEvryone).
Для хранения данных был использован контейнер Array.
