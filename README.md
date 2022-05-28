Użytkownik podaje w terminalu adres IPv4 z maska np. 192.168.0.1/24

Na wyjściu otrzymuje:
-adres sieci
-zakres adresów hostów
-ilość hostów
-adres broadcast

Wymagania:
-dobra organizacja kodu C++ napisana w modelu zorientowanym obiektowo (podział na pliki nagłówkowe i źródłowe),
-sprawdzanie poprawności podawanych parametrów wejściowych,
-nie korzystanie z bibliotek zewnętrznych (niestandardowych),
-wyjście dopisywane również do pliku znajdującego się w tym samym katalogu,
-wersja podstawowa programu obsługuje maski 8, 16, 24, dodatkowo można obsłużyć pozostałe maski (niekonieczne),
-finalny projekt Eclipse (eclipse.org) spakowany do archiwum zip lub projekt ze stworzonym makefile.

Przykładowy przebieg programu poniżej.
Podaj adres IPv4: 192.168.0.1/24
Wynik:
1) Adres sieci:    192.168.0.0/24
2) Zakres hostów:            192.168.0.1 - 192.168.0.254
3) Ilość hostów:                254
4) Adres broadcast:         192.168.0.255

Jeżeli chcesz opuścić program naciśnij 'e', jeżeli chcesz sprawdzić kolejny adres wciśnij enter.
