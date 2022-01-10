<script lang="ts">
  import { Recaptcha, recaptcha, observer } from "svelte-recaptcha-v2";

  let mailAddress = "test@mail.jp";
  let password = "password";
  let result = null;

  async function onSignIn() {
    const res = await fetch("http://localhost:8080/web/Account/signin", {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded;",
      },
      body: new URLSearchParams({ mailAddress: mailAddress, password: password }).toString(),
    });

    const json = await res.json();
    result = JSON.stringify(json);
  }

  function onCaptchaSuccess() {}
  function onCaptchaError() {}
  function onCaptchaExpire() {}
  function onCaptchaClose() {}
  function onCaptchaReady() {}

  // function onSignIn(googleUser) {
  //   var profile = googleUser.getBasicProfile();
  //   console.log("ID: " + profile.getId()); // Do not send to your backend! Use an ID token instead.
  //   console.log("Name: " + profile.getName());
  //   console.log("Image URL: " + profile.getImageUrl());
  //   console.log("Email: " + profile.getEmail()); // This is null if the 'email' scope is not present.
  // }
</script>

<!-- {#await fetchImage}
  <p>...waiting</p>
{:then data}
  <img src={data.message} alt="Dog image" />
{:catch error}
  <p>An error occurred!</p>
{/await} -->

<main>
  <h1>Todo App</h1>
  <div class="auth__form">
    <div class="form-group form-customize">
      <label for="email">メールアドレス</label>
      <input class="form-control" id="user_login" label="ユーザーIDまたはメールアドレス" name="user[login]" placeholder="メールアドレス" size="30" type="text" bind:value={mailAddress} />
    </div>
    <div class="form-group form-customize">
      <label for="password">パスワード</label>
      <input class="form-control" id="user_password" label="パスワード" name="user[password]" placeholder="パスワード" size="30" type="password" bind:value={password} />
    </div>
    s
    <Recaptcha sitekey={"googleRecaptchaSiteKey"} badge={"top"} size={"invisible"} on:success={onCaptchaSuccess} on:error={onCaptchaError} on:expired={onCaptchaExpire} on:close={onCaptchaClose} on:ready={onCaptchaReady} />
    b
    <!-- <noscript>
      <div>
        <div style="width: 302px; height: 422px; position: relative;">
          <div style="width: 302px; height: 422px; position: absolute;">
            <iframe src="https://www.google.com/recaptcha/api.js?hl=ja/fallback?k=6LfGBrMUAAAAAN_8yhR0mRG9o7S7c85YA6jE8fl_" scrolling="no" name="ReCAPTCHA" style="width: 302px; height: 422px; border-style: none; border: 0;" />
          </div>
        </div>
        <div
          style="width: 300px; height: 60px; border-style: none;
                    bottom: 12px; left: 25px; margin: 0px; padding: 0px; right: 25px;
                    background: #f9f9f9; border: 1px solid #c1c1c1; border-radius: 3px;"
        >
          <textarea
            id="g-recaptcha-response"
            name="g-recaptcha-response"
            class="g-recaptcha-response"
            style="width: 250px; height: 40px; border: 1px solid #c1c1c1;
                      margin: 10px 25px; padding: 0px; resize: none;"
          />
        </div>
      </div>
    </noscript> -->

    <div class="auth__button-submit">
      <button class="btn button button--primary button--large button--full" on:click={onSignIn}> ログイン </button>
    </div>
    <div class="text-center">
      <a href="/auth/password/new" class="auth__note-linkable">パスワードをお忘れですか？</a>
    </div>
    <div class="auth__horizontal-line text-center">OR</div>
    <!-- <div class="form-customize">
        <a class="btn button button--google button--large button--full" href="/auth/auth/google_oauth2">
          <span class="google-auth-icon" />
          Googleでログイン
        </a>
        <div class="auth__note-unlinkable text-center">Googleでアカウント作成をした方</div>
      </div> -->
    <!-- <div class="g-signin2" data-onsuccess={onSignIn} /> -->
  </div>
  <pre>
    {result}
  </pre>
</main>

<style>
  main {
    max-width: 300px;
    text-align: left;
    padding: 1em;
    margin: 0 auto;
  }

  h1 {
    color: #ff3e00;
    text-transform: uppercase;
    font-size: 4em;
    font-weight: 100;
  }

  /* @media (min-width: 640px) {
    main {
      max-width: none;
    }
  } */
</style>
