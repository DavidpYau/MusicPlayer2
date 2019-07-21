#pragma once
#include "IPlayerCore.h"
#include "bass.h"
#include "BASSMidiLibrary.h"
#include "Time.h"

class CBassCore :
    public IPlayerCore
{
public:
    CBassCore();
    ~CBassCore();

    virtual void InitCore() override;
    virtual void UnInitCore() override;
    virtual unsigned int GetHandle() override;

    virtual std::wstring GetAudioType() override;
    virtual int GetChannels() override;
    virtual int GetFReq() override;
    virtual const wstring& GetSoundFontName() override;

    virtual void Open(const wchar_t* file_path) override;
    virtual void Close() override;
    virtual void Play() override;
    virtual void Pause() override;
    virtual void Stop() override;
    virtual void SetVolume(int volume) override;

    virtual int GetCurPosition() override;
    virtual int GetSongLength() override;
    virtual void SetCurPosition(int position) override;
    virtual void GetAudioInfo(SongInfo& song_info, bool get_tag = true) override;
    virtual void GetAudioInfo(const wchar_t* file_path, SongInfo& song_info, bool get_tag = true) override;

    virtual bool IsMidi() override;
    virtual bool IsMidiConnotPlay() override;
    virtual std::wstring GetMidiInnerLyric() override;
    virtual MidiInfo GetMidiInfo() override;
    virtual bool MidiNoLyric() override;

    struct MidiLyricInfo 
    {
        wstring midi_lyric;
        bool midi_no_lyric;
    };

    virtual void ApplyEqualizer(int channel, int gain) override;
    virtual void SetReverb(int mix, int time) override;
    virtual void ClearReverb() override;
    virtual void GetFFTData(float fft_data[128]) override;

    static int GetBASSCurrentPosition(HSTREAM hStream);
    static Time GetBASSSongLength(HSTREAM hStream);
    static void SetCurrentPosition(HSTREAM hStream, int position);

    static void GetBASSAudioInfo(HSTREAM hStream, const wchar_t* file_path, SongInfo & song_info, bool get_tag);

public:
    static CBASSMidiLibrary m_bass_midi_lib;
    static BASS_MIDI_FONT m_sfont;	//MIDI��ɫ��

private:
    //��ȡMidi������Ƕ��ʵĻص�����
    static void CALLBACK MidiLyricSync(HSYNC handle, DWORD channel, DWORD data, void *user);
    static void CALLBACK MidiEndSync(HSYNC handle, DWORD channel, DWORD data, void *user);

    void GetMidiPosition();
    void SetFXHandle();		//������Ч���
    void RemoveFXHandle();		//�Ƴ���Ч���

private:
    HSTREAM m_musicStream{};		//��ǰ����Ƶ���
    wstring m_file_path;            //��ǰ��Ƶ�ļ���·��
    vector<HPLUGIN> m_plugin_handles;		//����ľ��
    wstring m_sfont_name;		//MIDI��ɫ�������
    static MidiLyricInfo m_midi_lyric;
    BASS_CHANNELINFO m_channel_info;	//��Ƶͨ������Ϣ
    bool m_is_midi;
    MidiInfo m_midi_info;

    int m_equ_handle[EQU_CH_NUM]{};		//������ͨ���ľ��
    int m_reverb_handle{};		//����ľ��
    const float FREQ_TABLE[EQU_CH_NUM]{ 80, 125, 250, 500, 1000, 1500, 2000, 4000, 8000, 1600 };		//ÿ��������ͨ��������Ƶ��

    int m_volume{60};

    enum { FADE_TIMER_ID = 1010 };
};
