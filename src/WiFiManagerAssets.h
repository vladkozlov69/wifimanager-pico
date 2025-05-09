#pragma once

/**
 * @brief HTML assets for captive portal used by WiFiManager classes.
 */



const char lock_img[] PROGMEM = R"=====(
    data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAAAXNSR0IArs4c6QAAATZJREFUSEvdlb8uBHEUhb+jl0g0Eh0KrMcQQiIa4UUkGn8rFB6EaIUQj7GLQieikGj0R36bKTazM3N3Z1bBLed37/lyz725I345NIi+7Q3gGJjN8l+BQ0k3UX0IsL0HnJUI7Uq6qIJUAmyvAnfAB5BA95nYCnAOTAHLkh7LIBHgIQkAO5KuekVsbwOXwK2k9bqAL2ACGJf0nQNMAp/Au6TpugCnQkmFndqufO/WVg0oEojeCwG2N7OtmY9WMPf+lK3ude/3vg5svwGlngbQtqSlCND1tW7k51XUwf8FpOEdAanDdB7WimxsYtGCpOckansGSAevL5oAWpI6GWARaI8akCw6AMaAE2Br1ICBNreJRX8HkIaXhlgnOpJa0alIwzsF5oYkvAD7kqqP3ZCiYXr40w8VgoQf8KKEGdyIA9gAAAAASUVORK5CYII=
)=====";

const char root_template[] PROGMEM = R"=====(
<html>
<head>
    <meta name='viewport' content='width=device-width, initial-scale=1, minimum-scale=1'/>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: #22272D;
        }

        .title {
            color: white;
            font-size: 28px;
            text-align: center;
        }

        .desc{
            color: #8293A6;
            font-size: 18px;
            text-align: center;
        }

        table {
            margin-left:auto;margin-right:auto;
        }

        .button {
            background-color: #22272D;
            border: #60BDC5;
            box-sizing: border-box;
            border-style: solid;
            border-width: 1px;
            border-radius: 4px;
            color: #8293A6;
            padding: 10px 32px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin: 4px 2px;
            transition-duration: 0.4s;
            cursor: pointer;
        }

        .button:hover {
            background-color: #60BDC5;
            color: white;
        }

        tr td:first-child {
           color: white;
           text-align: right;
           padding-right: 5px;
           font-size: 16px;
        }

        tr td {
           color: #8293A6;
           text-align: left;
           padding-left: 5px;
           font-size: 16px;
        }
      </style>
</head>
<body>
    <table>
        <tr>
            <td>
                <img src="${hero.img}" width="100px" alt="Hero logo"/>
            </td>
        </tr>
    </table>
    </div>
    <div class="title">PicoW</div>
    <p/>
    <div class="desc">Configure the WiFi connection for the following device</div>
    <p/>
    <table>
        <tr>
            <td>Name</td>
            <td>${firmware.name}</td>
        </tr>
        <tr>
            <td>Short name</td>
            <td>${firmware.shortname}</td>
        </tr>
        <tr>
            <td>Maker</td>
            <td>${firmware.maker}</td>
        </tr>
        <tr>
            <td>Version</td>
            <td>${firmware.version}</td>
        </tr>
    </table>
    <p/>
    <table>
        <tr>
            <td>
                <a class="button" href="/wifi">Configure WiFi</a>
            </td>
        </tr>
    </table>
</body>
</html>
)=====";

const char wifi_template[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta name='viewport' content='width=device-width, initial-scale=1, minimum-scale=1'/>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: #22272D;
        }

        .title {
            color: white;
            font-size: 28px;
            text-align: center;
        }

        .desc{
            color: #8293A6;
            font-size: 18px;
            text-align: center;
        }

        table {
            margin-left:auto;margin-right:auto;
        }

        .button {
            background-color: #22272D;
            border: #60BDC5;
            border-style: solid;
            border-width: 1px;
            border-radius: 4px;
            box-sizing: border-box;
            color: #8293A6;
            cursor: pointer;
            display: inline-block;
            padding: 10px 32px;
            font-size: 16px;
            margin: 4px 2px;
            text-align: center;
            text-decoration: none;
            transition-duration: 0.4s;
        }

        .button:hover {
            background-color: #60BDC5;
            color: white;
        }

        tr td {
           color: white;
           padding: 5px;
           font-size: 16px;
        }

        a {
            color: #48c0c7
        }

        .sec {
            text-align: right;
            width: 80px;
        }

        /* From https://hungyi.net/posts/pure-css-signal-indicator/ */
        .signal-icon {
            height: 18px;
            width: 18px;
            /* To show you the power of flexbox! */
            display: flex;
            /* Bars should be placed left to right */
            flex-direction: row;
            /* Evenly space the bars with space in between */
            justify-content: space-between;
            /* Sink the bars to the bottom, so they go up in steps */
            align-items: baseline;
        }

        .signal-icon .signal-bar {
            /* 4 + 3 + 4 + 3 + 4 = 18px (as set above)
                4px per bar and 3px margins between */
            width: 4px;
            /* All bars faded by default */
            opacity: 30%;
            /* Choose a color */
            background: white;
         }

        /* 3 different heights for 3 different bars */
        .signal-icon .signal-bar:nth-child(1) { height: 40%; }
        .signal-icon .signal-bar:nth-child(2) { height: 70%; }
        .signal-icon .signal-bar:nth-child(3) { height: 100%; }

        /* Emphasize different bars depending on
        weak/medium/strong classes */
        .signal-icon.weak .signal-bar:nth-child(1),
        .signal-icon.medium .signal-bar:nth-child(1),
        .signal-icon.medium .signal-bar:nth-child(2),
        .signal-icon.strong .signal-bar:nth-child(1),
        .signal-icon.strong .signal-bar:nth-child(2),
        .signal-icon.strong .signal-bar:nth-child(3)
        { opacity: 100%; }

        input[type=text], input[type=password] {
            padding: 6px;
            margin:4px 0;
            width:100%;
        }

        form {
            text-align: center;
        }

        td.sec img#lock {
            content: url(${img.lock});
            width: 20px;
        }

        td.sec img#unlock {
            /*content: url(${img.unlock});*/ /* no icon shown for insecure WiFi */
            width: 20px;
        }
    </style>
    <script>
        function setSSID(e) {
            var ssid = e.innerHTML;
            document.getElementById('ssid').value = ssid;
        }
    </script>
</head>
<body>
    <table>
        <tr>
            <td>
                <img src="${hero.img}" width="100px" alt="Hero logo"/>
            </td>
        </tr>
    </table>
    </div>
    <div class="title">PicoW</div>
    <p/>
    <div class="desc">Available WiFi Networks</div>
    <p/>
    <table>
        ${networks}
    </table>
    <p/>
    <br/>
    <table>
        <tr>
            <td>
            <div class="desc">WiFi Settings</div>
            </td>
        </tr>
    </table>
    <table>
        <tr>
            <td width="200px">
                <form method='POST' action='wifisave'>
                    <input id="ssid" type='text' placeholder='SSID' maxlength='32' name='n'/><br />
                    <input type='password' placeholder='Password' maxlength='32' name='p'/><br />
                    <input class="button" type='submit' value='Connect'/>
                </form>
            </td>
        </tr>
    </table>
    <table>
        <tr>
            <td>
                <p><a href='/'>Back to home</a></p>
            </td>
        </tr>
    </table>
</body>
</html>
)=====";

const char wifi_network_template[] PROGMEM = R"=====(
    <tr>
        <td>
            <div class="signal-icon ${signal}">
                <div class="signal-bar"></div>
                <div class="signal-bar"></div>
                <div class="signal-bar"></div>
            </div>
        </td>
        <td><a onclick="javascript:setSSID(this)" href="javascript:">${name}</a></td>
        <td class="sec">
            <img id="${network.security}"/>
        </td>
    </tr>
)=====";
