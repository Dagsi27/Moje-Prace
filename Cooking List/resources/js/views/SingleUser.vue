<template>
    <div>
        <Header siteName="User"></Header>
        <SingleUser></SingleUser>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from '../components/header/HeaderGlobal';
import SingleUser from '../components/content/SingleUser';
import Footer from '../components/footer/Footer';
export default {

  components: {
    Header,
    SingleUser,
    Footer
  }
}
</script>
