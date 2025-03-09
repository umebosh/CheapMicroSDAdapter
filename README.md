# microSD Converter for Raspberry Pi Pico

このリポジトリでは、Raspberry Pi PicoとmicroSDカードを接続してSDカードを読み取るための簡易的な回路例を紹介しています。  
下記のピン接続を行い、[image.png](./image.png) のように配線することで、PicoからmicroSDカードへアクセスできるようになります。

## 配線例

- microSDコネクタ `CS` ピン → Pico `GPIO7`
- microSDコネクタ `MOSI` ピン → Pico `GPIO5`
- microSDコネクタ `MISO` ピン → Pico `GPIO6`
- microSDコネクタ `CLK` ピン → Pico `GPIO4`
- その他、3.3V電源とGNDを正しく接続してください

詳細なピンアサインやライブラリの使い方については、ソースコードや各種ドキュメントを参照してください。
