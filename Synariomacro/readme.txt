◆ファイル構成:

>macro_synario.exe
>macro_synario.pdb


◆使用方法:

>1.変換前のprimitiveのsheet情報Ctrl + Aで全コピーする。
>2.*.csvファイルのA1にCtrl + Vでコピーする。
>3.*.csvを保存する。
>4.変換後のprimitiveも同様にする。
>5.制限事項1を考えながら、作った2ファイルを同時にmacro_synario.exeにドラッグアンドドロップする。
>6.currValue.txtが出力される。


◆制限事項:

>1.ラッグアンドドロップする際には、変更前の*.csvがargv[1],変更後の*.csvがagrv[2]になるようにドラッグアンドドロップする。
>2.keyの重複は考慮できなかったため、重複する値はxxxxxxxxに出力される。

◆推奨:

>ローカル環境で使用することを進める。