package org.ispeech.sdksample;

import org.ispeech.SpeechSynthesis;
import org.ispeech.SpeechSynthesisEvent;
import org.ispeech.error.BusyException;
import org.ispeech.error.InvalidApiKeyException;
import org.ispeech.error.NoNetworkException;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.media.AudioManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.EditText;
import android.widget.Toast;

/**
 * 
 *
 */
public class TTSActivity extends Activity {

	private static final String TAG = "iSpeech SDK Sample";
	SpeechSynthesis synthesis;
	Context _context;


	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);		
		_context = this.getApplicationContext();

		setContentView(R.layout.tts);

		((EditText) findViewById(R.id.text)).setText(R.string.tts_sample_text);
		findViewById(R.id.speak).setOnClickListener(new OnSpeakListener());
		findViewById(R.id.stop).setOnClickListener(new OnStopListener());
		
		prepareTTSEngine();
		
		synthesis.setStreamType(AudioManager.STREAM_MUSIC); 
	}


	private void prepareTTSEngine() {
		try {
			synthesis = SpeechSynthesis.getInstance(this);
			synthesis.setSpeechSynthesisEvent(new SpeechSynthesisEvent() {

				public void onPlaySuccessful() {
					Log.i(TAG, "onPlaySuccessful");
				}

				public void onPlayStopped() {
					Log.i(TAG, "onPlayStopped");
				}

				public void onPlayFailed(Exception e) {
					Log.e(TAG, "onPlayFailed");
					

					AlertDialog.Builder builder = new AlertDialog.Builder(TTSActivity.this);
					builder.setMessage("Error[TTSActivity]: " + e.toString())
					       .setCancelable(false)
					       .setPositiveButton("OK", new DialogInterface.OnClickListener() {
					           public void onClick(DialogInterface dialog, int id) {
					           }
					       });
					AlertDialog alert = builder.create();
					alert.show();
				}

				public void onPlayStart() {
					Log.i(TAG, "onPlayStart");
				}

				@Override
				public void onPlayCanceled() {
					Log.i(TAG, "onPlayCanceled");
				}
			});


		} catch (InvalidApiKeyException e) {
			Log.e(TAG, "Invalid API key\n" + e.getStackTrace());
			Toast.makeText(_context, "ERROR: Invalid API key", Toast.LENGTH_LONG).show();
		}
	}


	private class OnSpeakListener implements OnClickListener {

		public void onClick(View v) {
			
			try {
				String ttsText = ((EditText) findViewById(R.id.text)).getText().toString();
				
				synthesis.speak(ttsText);

			} catch (BusyException e) {
				Log.e(TAG, "SDK is busy");
				e.printStackTrace();
				Toast.makeText(_context, "ERROR: SDK is busy", Toast.LENGTH_LONG).show();
			} catch (NoNetworkException e) {
				Log.e(TAG, "Network is not available\n" + e.getStackTrace());
				Toast.makeText(_context, "ERROR: Network is not available", Toast.LENGTH_LONG).show();
			}
		}
	}

	
	public class OnStopListener implements OnClickListener {

		public void onClick(View v) {
			if (synthesis != null) {
				synthesis.stop();
			}
		}
	}


	@Override
	protected void onPause() {
		synthesis.stop();	//Optional to stop the playback when the activity is paused
		super.onPause();
	}
}