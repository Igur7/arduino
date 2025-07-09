import serial
import time
from ctypes import cast, POINTER
from pycaw.pycaw import AudioUtilities, ISimpleAudioVolume

ser = serial.Serial('COM5', 9600)
last_volume = 0.5
kill_active = False

def get_spotify_volume_interface():
    sessions = AudioUtilities.GetAllSessions()
    for session in sessions:
        if session.Process and "Spotify" in session.Process.name():
            return session._ctl.QueryInterface(ISimpleAudioVolume)
    return None

while True:
    try:
        line = ser.readline().decode().strip()

        spotify = get_spotify_volume_interface()
        if not spotify:
            print("❗ Spotify nie działa")
            continue
        if line == "KILL":
            if not kill_active:
                last_volume = spotify.GetMasterVolume()
                spotify.SetMasterVolume(0.0, None)
                print(" KILL SWITCH AKTYWNY")
                kill_active = True
            else:
                spotify.SetMasterVolume(last_volume, None)
                print(f"🔊 KILL OFF – przywracam: {round(last_volume * 100)}%")
                kill_active = False

        # Obsługa potencjometru
        elif line.isdigit():
            value = int(line)
            volume = value / 1023

            if not kill_active and abs(volume - last_volume) > 0.02:
                spotify.SetMasterVolume(volume, None)
                last_volume = volume
                print(f"🎚 {round(volume * 100)}%")

        time.sleep(0.05)

    except Exception as e:
        print("Błąd:", e)
