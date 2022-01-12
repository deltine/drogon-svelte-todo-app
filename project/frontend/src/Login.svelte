<script lang="ts">
  // import { Button, Icon, Styles } from "sveltestrap";
  import Textfield from "@smui/textfield";
  import HelperText from "@smui/textfield/helper-text";
  import Button, { Label } from "@smui/button";
  import { push } from "svelte-spa-router";

  let mailAddress = "test@mail.jp";
  let password = "password";

  async function onSignIn() {
    const res = await fetch("http://localhost:8080/web/Account/signin", {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded;",
      },
      body: new URLSearchParams({ mailAddress: mailAddress, password: password }).toString(),
    });

    const json = await res.json();
    // console.log("res" + json["res"]);
    if (json["res"] == "1") {
      // console.log("success");
      push("/todo");
    }

    // state = State.requesting;
    // doRecaptcha();
  }

  // recaptcha
  // const key = "6Ldvac0ZAAAAAFmtvwilkJ3MOD4IGou9KjhRglIo";
  // let State = {
  //   idle: "idle",
  //   requesting: "requesting",
  //   success: "success",
  // };
  // let token;
  // let state = State.idle;

  // function doRecaptcha() {
  //   grecaptcha.ready(function () {
  //     grecaptcha.execute(key, { action: "submit" }).then(function (t) {
  //       state = State.success;
  //       token = t;
  //     });
  //   });
  // }

  // function toggle() {
  //   window.document.body.classList.toggle("dark-mode");
  // }
</script>

<!-- <svelte:head>
  <script src="https://apis.google.com/js/platform.js" async defer></script>
  <script src="https://www.google.com/recaptcha/api.js?render={key}" async defer></script>
</svelte:head> -->

<!-- {#await fetchImage}
  <p>...waiting</p>
{:then data}
  <img src={data.message} alt="Dog image" />
{:catch error}
  <p>An error occurred!</p>
{/await} -->

<!-- <div>state: {state}</div>
token:<br />{token} -->

<!-- <Styles />
<Button color="primary">
  Nice! <Icon name="emoji-smile-fill" />
</Button>
<button on:click={toggle}>
  <slot />
</button> -->

<main>
  <h1>Todo App</h1>
  <div class="auth__form">
    <div class="form-group form-customize">
      <!-- <label for="email">メールアドレス</label>
      <input class="form-control" id="user_login" label="ユーザーIDまたはメールアドレス" name="user[login]" placeholder="メールアドレス" size="30" type="text" bind:value={mailAddress} /> -->
      <Textfield bind:value={mailAddress} label="メールアドレス">
        <HelperText slot="helper">メールアドレスを入力して下さい</HelperText>
      </Textfield>
    </div>
    <div class="form-group form-customize">
      <!-- <label for="password">パスワード</label>
      <input class="form-control" id="user_password" label="パスワード" name="user[password]" placeholder="パスワード" size="30" type="password" bind:value={password} /> -->
      <Textfield bind:value={password} label="パスワード">
        <HelperText slot="helper">パスワードを入力して下さい</HelperText>
      </Textfield>
    </div>
    <div class="auth__button-submit">
      <!-- <button class="btn button button--primary button--large button--full" on:click={onSignIn}> ログイン </button> -->
      <Button on:click={onSignIn} variant="unelevated">
        <Label>ログイン</Label>
      </Button>
    </div>
    <div class="g-signin2" data-longtitle="true" data-onsuccess="onSignIn" />
  </div>
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
</style>
